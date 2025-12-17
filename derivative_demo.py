from manim import *

class DerivativeConcept(Scene):
    def construct(self):
        # 创建坐标系
        axes = Axes(
            x_range=[-3, 3, 1],
            y_range=[-2, 10, 1],
            x_length=8,
            y_length=6,
            axis_config={"color": BLUE},
        )
        
        # 添加坐标轴标签
        axes_labels = axes.get_axis_labels(x_label="x", y_label="f(x)")
        
        # 定义函数 f(x) = x²
        func = lambda x: x**2
        graph = axes.plot(func, color=GREEN)
        func_label = MathTex(r"f(x) = x^2").next_to(graph, UR, buff=0.1)
        
        # 选择点 a = 1
        a = 1
        point_a = axes.coords_to_point(a, func(a))
        dot_a = Dot(point_a, color=RED)
        dot_label = MathTex(r"a", color=RED).next_to(dot_a, DR, buff=0.1)
        
        # 添加函数和点的说明
        title = Tex("导数的几何意义").scale(1.2).to_edge(UP)
        title.set_color(YELLOW)
        
        # 显示坐标轴和函数
        self.play(Write(title))
        self.play(Create(axes), Write(axes_labels))
        self.play(Create(graph), Write(func_label))
        self.wait()
        
        # 显示点a
        self.play(Create(dot_a), Write(dot_label))
        self.wait()
        
        # 切线斜率的定义
        definition = MathTex(r"f'(a) = \lim_{h \to 0} \frac{f(a+h) - f(a)}{h}")
        definition.next_to(title, DOWN)
        definition.shift(RIGHT*0.5)
        
        self.play(Write(definition))
        self.wait(2)
        
        # 创建割线
        h_values = [2, 1, 0.5, 0.2, 0.1]
        secant_lines = []
        secant_formulas = []
        
        for i, h in enumerate(h_values):
            # 计算第二个点
            point_h = axes.coords_to_point(a + h, func(a + h))
            dot_h = Dot(point_h, color=ORANGE)
            
            # 创建割线
            secant_line = Line(point_a, point_h, color=YELLOW)
            
            # 计算斜率公式
            slope_formula = MathTex(
                r"\frac{f(%.1f) - f(1)}{%.1f}" % (a+h, h) + 
                r" = \frac{%.2f - 1}{%.1f}" % (func(a+h), h)
            ).to_edge(RIGHT)
            
            # 动画显示
            self.play(Create(dot_h), Create(secant_line))
            self.play(Write(slope_formula))
            self.wait(0.5)
            
            # 保存对象以便后续移除
            secant_lines.append((secant_line, dot_h, slope_formula))
            
            # 如果不是最后一个，移除当前显示
            if i < len(h_values) - 1:
                self.play(
                    FadeOut(secant_line),
                    FadeOut(dot_h),
                    FadeOut(slope_formula)
                )
        
        # 清除最后一个割线的公式
        self.play(FadeOut(secant_lines[-1][2]))
        
        # 显示切线（导数）
        tangent_slope = 2*a  # f'(x) = 2x，在x=1处斜率为2
        tangent_line = axes.plot(
            lambda x: tangent_slope*(x-a) + func(a),
            x_range=[a-1.5, a+1.5],
            color=RED
        )
        
        tangent_label = MathTex(r"y = f'(1)(x-1) + f(1)").next_to(tangent_line, LEFT)
        
        # 显示切线
        self.play(Transform(secant_lines[-1][0], tangent_line))
        self.play(Write(tangent_label))
        self.wait()
        
        # 显示导数值
        derivative_value = MathTex(r"f'(1) = 2").next_to(tangent_label, DOWN)
        self.play(Write(derivative_value))
        self.wait(2)
        
        # 总结
        summary = VGroup(
            Tex("导数 $f'(a)$ 表示："),
            Tex("1. 函数在 $x=a$ 处的瞬时变化率"),
            Tex("2. 函数曲线在 $x=a$ 处的切线斜率"),
            Tex("3. 当 $h\\to 0$ 时割线斜率的极限")
        ).arrange(DOWN, aligned_edge=LEFT).scale(0.8)
        
        summary.to_edge(DOWN).shift(UP*0.5)
        summary[0].set_color(GREEN)
        
        self.play(Write(summary))
        self.wait(3)

class DerivativeAsLimit(Scene):
    """另一个更详细的导数演示"""
    def construct(self):
        # 标题
        title = Text("导数：变化率的极限", font_size=36)
        title.to_edge(UP)
        self.play(Write(title))
        
        # 定义导数为极限
        limit_def = MathTex(
            r"f'(x) = \lim_{h \to 0} \frac{f(x+h) - f(x)}{h}"
        ).next_to(title, DOWN)
        
        self.play(Write(limit_def))
        self.wait()
        
        # 创建数值示例表格
        example_title = Tex("示例：$f(x) = x^2$, $x=1$").next_to(limit_def, DOWN)
        self.play(Write(example_title))
        self.wait()
        
        # 创建表格
        table = Table(
            [["h", r"$\frac{f(1+h)-f(1)}{h}$", "近似导数"],
             ["1.0", r"$\frac{4-1}{1}=3$", "3.00"],
             ["0.5", r"$\frac{2.25-1}{0.5}=2.5$", "2.50"],
             ["0.1", r"$\frac{1.21-1}{0.1}=2.1$", "2.10"],
             ["0.01", r"$\frac{1.0201-1}{0.01}=2.01$", "2.01"],
             ["0.001", r"$\frac{1.002001-1}{0.001}=2.001$", "2.001"],
             ["→0", "→2", "→2.00"]],
            include_outer_lines=True
        ).scale(0.5)
        
        table.next_to(example_title, DOWN)
        
        self.play(Create(table))
        self.wait(3)
        
        # 结论
        conclusion = Tex("当 $h$ 趋近于 0，差商趋近于导数 $f'(1)=2$")
        conclusion.next_to(table, DOWN)
        conclusion.set_color(YELLOW)
        
        self.play(Write(conclusion))
        self.wait(3)

class InteractiveTangent(Scene):
    """交互式切线演示"""
    def construct(self):
        # 创建坐标系
        axes = Axes(
            x_range=[-2, 2, 1],
            y_range=[-1, 4, 1],
            axis_config={"color": BLUE},
        )
        
        # 函数 f(x) = x^2
        func = axes.plot(lambda x: x**2, color=GREEN)
        func_label = MathTex("f(x) = x^2").to_corner(UL)
        
        # 可移动的点
        dot = Dot(color=RED)
        dot.move_to(axes.coords_to_point(1, 1))
        
        # 切线
        tangent_line = always_redraw(
            lambda: axes.plot(
                lambda x: 2*dot.get_center()[0]/axes.x_length*(x*2) - 
                         (dot.get_center()[0]/axes.x_length*2)**2 + 
                         func(dot.get_center()[0]/axes.x_length*2),
                color=RED,
                x_range=[-2, 2]
            ) if hasattr(dot, 'get_center') else axes.plot(lambda x: x, color=RED)
        )
        
        # 斜率标签
        slope_label = always_redraw(
            lambda: MathTex(
                f"f'({dot.get_center()[0]/axes.x_length*2:.2f}) = " + 
                f"{2*(dot.get_center()[0]/axes.x_length*2):.2f}"
            ).next_to(dot, UR, buff=0.1)
        )
        
        # 动画
        self.add(axes, func, func_label, dot, tangent_line, slope_label)
        self.wait()
        
        # 移动点演示不同位置的切线
        points_to_visit = [
            axes.coords_to_point(-1.5, 2.25),
            axes.coords_to_point(-0.5, 0.25),
            axes.coords_to_point(0, 0),
            axes.coords_to_point(0.5, 0.25),
            axes.coords_to_point(1.5, 2.25),
        ]
        
        for point in points_to_visit:
            self.play(dot.animate.move_to(point), run_time=2)
            self.wait(0.5)
        
        self.wait(2)

# 运行提示
"""
运行方式：
1. 安装 manim: pip install manim
2. 保存为 derivative_demo.py
3. 运行: manim -pql derivative_demo.py DerivativeConcept
   -p: 预览
   -q: 质量等级 (l=低, m=中, h=高, k=4K)
   -l: 低质量（快速渲染）

更多演示：
manim -pql derivative_demo.py DerivativeAsLimit
manim -pql derivative_demo.py InteractiveTangent
"""
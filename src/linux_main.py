import subprocess
import gradio as gr

def call_cpp_program(a, b):
    # 调用C++程序
    result = subprocess.run(['./calculator', str(a), str(b)], capture_output=True, text=True)
    
    # 返回C++程序的输出
    return result.stdout

iface = gr.Interface(
    title="Calculator: For Cpp Project",
    description = r"""<center><img src='https://raw.githubusercontent.com/Justin-12138/Calculator/778e0ca56e8b5672064e2b5866f6cf0d3aef8178/doc/cpp.svg' alt='CPP'></center>
    <b>Official Gradio demo</b> for <a href='https://github.com/Justin-12138/Calculator' target='_blank'><b>Calculater</b></a>.<br>
    """,
    fn=call_cpp_program,  # 处理函数
    inputs=[gr.inputs.Number(label="number a"), gr.inputs.Number(label="number b")],  # 输入组件
    outputs="text",  # 输出组件
    allow_flagging="never"
    
)

iface.launch()


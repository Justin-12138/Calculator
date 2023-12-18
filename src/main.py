# main.py
import gradio as gr
import subprocess

def calculate(expression):
    result = subprocess.run(["./calculator.exe"], input=expression, text=True, capture_output=True)
    return result.stdout

# buttons = [
#     gr.inputs.Button(label=str(i)) for i in range(10)
# ] + [
#     gr.inputs.Button(label=c) for c in ['+', '-', '*', '/', '.', 'AC', '=']
# ]
iface = gr.Interface(
    title="Calculator: For Cpp Project",
    description = r"""<center><img src='https://raw.githubusercontent.com/Justin-12138/Calculator/778e0ca56e8b5672064e2b5866f6cf0d3aef8178/doc/cpp.svg' alt='CPP'></center>
    <b>Official Gradio demo</b> for <a href='https://github.com/Justin-12138/Calculator' target='_blank'><b>Calculater</b></a>.<br>
    """,
    fn=calculate,  # 处理函数
    inputs="text",  # 输入组件
    outputs="text",  # 输出组件
    allow_flagging="never"
    
)

iface.launch(auth=("admin", "pass1234"),server_name='0.0.0.0', server_port=7860)
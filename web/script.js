let display = document.getElementById('display');

function appendToDisplay(value) {
    display.value += value;
}

function clearDisplay() {
    display.value = '';
}

async function calculate() {
    try {
        const expression = display.value;
        const response = await fetch('/calculate', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({ expression: expression })
        });

        const data = await response.json();
        if (data.error) {
            throw new Error(data.error);
        }
        display.value = data.result;
    } catch (error) {
        display.value = 'Error';
        console.error('Calculation error:', error);
    }
}
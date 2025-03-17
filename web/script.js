class CalculatorUI {
    constructor() {
        this.display = document.getElementById('display');
        this.historyList = document.getElementById('history');
        this.initEventListeners();
    }

    initEventListeners() {
        document.querySelectorAll('.buttons button').forEach(button => {
            if (!button.classList.contains('equals')) {
                button.addEventListener('click', () => this.appendToDisplay(button.textContent));
            }
        });

        document.getElementById('clear').addEventListener('click', () => this.clearDisplay());
        document.getElementById('calculate').addEventListener('click', () => this.calculate());
    }

    appendToDisplay(value) {
        this.display.value += value;
    }

    clearDisplay() {
        this.display.value = '';
    }

    async calculate() {
        const expression = this.display.value;
        if (!expression) return;

        try {
            const result = await this.fetchCalculation(expression);
            this.display.value = result;
            this.addToHistory(expression, result);
        } catch (error) {
            this.display.value = 'Error';
            console.error('Calculation error:', error);
        }
    }

    async fetchCalculation(expression) {
        const response = await fetch('/api/calculate', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({ expression })
        });

        const data = await response.json();
        if (data.error) {
            throw new Error(data.error);
        }
        return data.result;
    }

    addToHistory(expression, result) {
        const li = document.createElement('li');
        li.innerHTML = `<span class="expression">${expression}</span> = <span class="result">${result}</span>`;
        this.historyList.prepend(li);
    }
}

new CalculatorUI();
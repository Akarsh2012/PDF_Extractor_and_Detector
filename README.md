# 📄 PDF Table Extractor using C++ & Python

A hybrid **C++ + Python** tool to detect and extract **tabular data from native PDFs** (non-scanned) without using heavy libraries like **Tabula**, **Camelot**, or converting PDF to images. The tables are automatically detected using spatial logic and exported to clean **Excel** files.

---

## ✨ Features

- ⚡ High-speed processing using C++ logic.
- 🐍 Python integration for parsing PDFs and writing to Excel.
- 📄 No image conversion, works directly on native PDFs.
- 📄 Extracted tables are saved as `.xlsx` files.
- 📁 Clean, modular folder structure.
- 💪 Perfect for research, hackathons, or custom automation.

---

## 🧹 Project Structure

```plaintext
pdf_table_extractor/
├── input/
│   └── your_file.pdf              # Your input PDFs go here
├── output/
│   └── table_output.xlsx          # Excel files are generated here
├── scripts/
│   └── extract_tables.py          # Main Python orchestrator script
├── venv/                          # Python virtual environment
├── requirements.txt               # Python dependencies (optional)
└── README.md                      # Project documentation (this file)
```

---

## ⚙️ Technologies Used

- **C++ (G++)** — Custom logic to detect table rows/columns using text position.
- **Python 3.8+**
  - `PyMuPDF (fitz)` — PDF parsing and coordinate extraction
  - `openpyxl` — Write to Excel
  - `json` & `subprocess` — Data exchange between C++ and Python

---

## 🔧 Setup Instructions

### 1. Clone the Repo
```bash
git clone https://github.com/yourusername/pdf_table_extractor.git
cd pdf_table_extractor
```

### 2. Create & Activate Virtual Environment (Recommended)
```bash
python -m venv venv
source venv/bin/activate  # Linux / macOS
venv\Scripts\activate     # Windows
```

### 3. Install Python Dependencies
```bash
pip install -r requirements.txt
```

> `requirements.txt` should contain:
```
PyMuPDF
openpyxl
```

---

## 🏗️ Compile C++ Table Detector

Make sure you're in the root directory and run:

```bash
g++ scripts/table_detector.cpp -o scripts/table_detector
```

This compiles the core C++ logic into an executable `table_detector`.

---

## ▶️ Run the Full Pipeline

```bash
python scripts/extract_tables.py
```

This will:

1. Load PDF from `input/your_file.pdf`.
2. Use PyMuPDF to extract text & positions.
3. Pass structured JSON to `table_detector.cpp`.
4. C++ returns detected tables.
5. Final Excel output saved in `output/table_output.xlsx`.

---

## 📂 Output

Check `output/table_output.xlsx` — It will contain a clean spreadsheet version of the detected tables from your input PDF.

---

## 🧐 How It Works

```plaintext
[Python]
  └── Extract text + x/y positions using PyMuPDF
  └── Format data into JSON

[C++]
  └── Parse JSON
  └── Detect rows based on Y-coordinates
  └── Detect columns using X-coordinate clustering
  └── Output as structured table (back to JSON)

[Python]
  └── Write to Excel using openpyxl
```

---

## 🧪 Sample PDF to Test

Place your PDF file inside `input/` as `your_file.pdf`, and just run:

```bash
python scripts/extract_tables.py
```

---

## 📌 Future Work

- [ ] Add support for multi-page PDFs
- [ ] Improve column alignment for irregular tables
- [ ] Add web-based interface using Flask/FastAPI
- [ ] Add CLI options to extract specific pages

---

## 🧠 Author

**Akarsh** — MNNIT Allahabad  
If you liked it or used it in a hackathon, give it a ⭐

---

## 📜 License

MIT License — Free to use, share, and modify.

---

## 🙌 Acknowledgments

Thanks to the challenge that inspired this:  
> _“Extract tables from PDFs without using Tabula, Camelot, or image processing”_  
A real test of logic and optimization 💡


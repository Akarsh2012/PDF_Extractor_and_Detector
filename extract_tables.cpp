#include <iostream>
#include <fstream>
#include <string>
#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>

using namespace std;

void extract_text_from_pdf(const string &pdf_path, const string &output_txt)
{
    auto doc = poppler::document::load_from_file(pdf_path);
    if (!doc)
    {
        cerr << "❌ Error: Cannot open PDF file!" << endl;
        return;
    }

    ofstream output(output_txt);
    if (!output.is_open())
    {
        cerr << "❌ Error: Cannot create output file!" << endl;
        return;
    }

    for (int i = 0; i < doc->pages(); ++i)
    {
        auto page = doc->create_page(i);
        if (!page)
            continue;

        // Extract text as ustring
        poppler::ustring utext = page->text();

        // Convert ustring to std::string
        std::vector<char> utf8_vec = utext.to_utf8();
        std::string text(utf8_vec.begin(), utf8_vec.end());

        output << text << "\n";
        output << "--- End of Page " << i + 1 << " ---\n";
    }

    output.close();
    cout << "✅ Text extracted successfully to " << output_txt << endl;
}

int main()
{
    string pdf_file = "data/input2.pdf";
    string output_file = "data/output.txt";

    extract_text_from_pdf(pdf_file, output_file);
    return 0;
}

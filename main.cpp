#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>

int main() {
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

    if (api->Init(NULL, "eng")) {
        std::cerr << "Could not initialize tesseract.\n";
        return 1;
    }

    Pix *image = pixRead("sample_image.png");
    if (!image) {
        std::cerr << "Cannot open input image!\n";
        return 1;
    }

    api->SetImage(image);
    char* outText = api->GetUTF8Text();
    std::cout << "OCR Output:\n" << outText << std::endl;

    api->End();
    delete [] outText;
    pixDestroy(&image);
    return 0;
}
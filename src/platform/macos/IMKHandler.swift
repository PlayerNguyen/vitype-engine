import Cocoa
import InputMethodKit

class IMKHandler: IMKInputController {
    private var converter: OpaquePointer?

    override init!(server: IMKServer?, delegate: Any?, client inputClient: Any?) {
        super.init(server: server, delegate: delegate, client: inputClient)
        converter = createConverter() // Gọi C++ thông qua C API
    }

    override func handle(_ event: NSEvent!, client sender: Any!) -> Bool {
        if let inputText = event.characters {
            let convertedText = convert(inputText)
            NSLog("Converted: \(convertedText)")
        }
        return true
    }

    private func convert(_ text: String) -> String {
        guard let cStr = text.cString(using: .utf8) else { return text }
        guard let result = convertText(converter, cStr) else { return text }
        return String(cString: result)
    }

    deinit {
        destroyConverter(converter)
    }
}

# Contributing to LoraComm

Thank you for your interest in contributing to the LoraComm project! This document provides guidelines and instructions for contributing.

---

## Code of Conduct

This project adheres to the Contributor Covenant Code of Conduct. By participating, you are expected to uphold this code. Please read [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md).

---

## How to Contribute

### Reporting Bugs

Before reporting a bug:
1. Check existing [GitHub Issues](https://github.com/harineasht-ec25/LoraComm---RF-Based-Switching/issues)
2. Search closed issues as well

**When reporting, include**:
- Clear, descriptive title
- Detailed description of the bug
- Steps to reproduce
- Expected behavior vs actual behavior
- Hardware configuration (ESP32 version, LoRa module model, etc.)
- Code snippet if applicable
- Error messages or log output

### Suggesting Features

**Feature Request Template**:
- Clear, descriptive title
- Description of the proposed feature
- Motivation and use cases
- Possible implementation approach

### Pull Requests

We actively welcome pull requests!

#### Before Starting

1. **Fork the repository**
2. **Create a feature branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```

#### Development Guidelines

**Code Style**:
- Language: C++ (Arduino sketch)
- Indentation: 2 spaces (NO tabs)
- Line Length: Maximum 100 characters
- Naming: `camelCase()` for functions, `UPPER_SNAKE_CASE` for constants

**Comments**:
- Add comments explaining non-obvious logic
- Document function parameters and return values
- Include examples for complex functions

#### Testing Your Changes

1. **Hardware Testing**
   - Test on actual ESP32 and LoRa hardware
   - Verify both Transmitter and Receiver modes

2. **Serial Output**
   - Check Serial monitor for debug messages
   - Verify no compiler warnings

#### Commit Messages

- Use clear, descriptive commit messages
- Start with a verb (Add, Fix, Update, Remove, etc.)
- Reference issues: "Fix #123"

**Examples**:
```
Add encryption support for message transmission
Fix SPI communication timeout issue
Update API documentation with new functions
```

---

## Project Structure

```
LoraComm---RF-Based-Switching/
├── .github/              # GitHub workflows and templates
├── docs/                 # Documentation
├── firmware/             # Arduino sketches
│   ├── transmitter/
│   ├── receiver/
│   ├── utilities/
│   └── include/
├── hardware/             # PCB designs
├── tests/                # Test code
├── examples/             # Example projects
├── CONTRIBUTING.md       # This file
├── CODE_OF_CONDUCT.md    # Community standards
└── README.md             # Project overview
```

---

## Questions?

Have questions about contributing? 
- Open an issue with the `question` label
- Check existing documentation

---

## License

By contributing, you agree that your contributions will be licensed under the MIT License.

Thank you for contributing to LoraComm! 🚀

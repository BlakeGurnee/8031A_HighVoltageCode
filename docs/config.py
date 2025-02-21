import os
import sys
sys.path.insert(0, os.path.abspath(".."))  # Ensure Sphinx can find your project files

# Project Information
project = "VEX Robotics Documentation"
author = "High Voltage 8031A"
release = "1.0"

# General Configuration
extensions = [
    "sphinx.ext.autodoc",  # Automatically generate documentation from docstrings
    "sphinx.ext.napoleon",  # Support for Google-style docstrings
    "sphinx.ext.viewcode",  # Add links to source code
]

templates_path = ["_templates"]
exclude_patterns = []

# HTML Output Configuration
html_theme = "sphinx_rtd_theme"
html_static_path = ["_static"]

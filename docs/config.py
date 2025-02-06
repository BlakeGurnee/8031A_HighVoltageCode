# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = "8031A High Voltage Code"
copyright = "2025, Blake Gurnee"
author = "Blake Gurnee"

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = ["myst_parser", "breathe"]

templates_path = ["_templates"]
exclude_patterns = []


# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = "furo"
html_static_path = ["_static"]

html_theme_options = {
    "light_css_variables": {
        "color-brand-primary": "#FF67E3",
        "color-brand-content": "#FF67E3",
    },
    "dark_css_variables": {
        "color-brand-primary": "#FF67E3",
        "color-brand-content": "#FF67E3",
    },
}

# -- Extension configuration -------------------------------------------------

myst_enable_extensions = [
    "amsmath",
    "attrs_inline",
    "colon_fence",
    "deflist",
    "dollarmath",
    "fieldlist",
    "html_admonition",
    "html_image",
    "replacements",
    "smartquotes",
    "strikethrough",
    "substitution",
    "tasklist",
]

breathe_projects = {"8031A High Voltage Code": "../doxygen/xml/"}

breathe_default_project = "8031A High Volatge Code"


# -- Run Doxygen -------------------------------------------------------------

import subprocess, os

read_the_docs_build = os.environ.get("READTHEDOCS", None) == "True"

if read_the_docs_build:
    subprocess.call("cd ..; doxygen", shell=True)

from fpdf import FPDF

name= input("Gib name: ")
text = f'{name} took CS50'

pdf = FPDF()
pdf.add_page()
pdf.set_font("helvetica", "B", 16)
pdf.cell(0, 10, 'CS50 Shirtificate', align='C')
pdf.ln(20)
pdf.image("shirtificate.png", w=pdf.epw)
pdf.set_text_color(255, 255,255)
pdf.cell(0, -250, text, align='C')
# pdf.cell(40, 10, "Hello World!")
pdf.output("shirtificate.pdf")
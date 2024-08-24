from bs4 import BeautifulSoup

def count_table_rows(html_string):
    # Parse the HTML string
    soup = BeautifulSoup(html_string, 'html.parser')
    
    # Find the table element
    table = soup.find('table')
    
    if not table:
        return 0  # If no table is found, return 0
    
    # Find all the rows in the table
    rows = table.find_all('tr')
    
    # Return the number of rows
    return len(rows)

# Example HTML string
html_string = '''
<table border="0" cellspacing="0" cellpadding="0" width="873" style="width:655.05pt;border-collapse:collapse">
<tbody>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">404<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">PEC UNIVERSITY OF TECHNOLOGY<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Ishita<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">#CodeWithUs<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Institute of Engineering and Technology Devi Ahilya Vishwavidyalaya, Indore<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Ayush Mishra<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">1 Code 3 Hangovers<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Pimpri Chinchwad College of Engineering, Pune<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Abhijeet<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">12th_Fail<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Indian Institute of Information Technology, Pune<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Saurabh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">404 Found<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Kurukshetra<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jai Sehgal<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">404found<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jaypee Institute of Information Technology, Noida<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Ankur Chaudhary<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">AAA3<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jaypee Institute of Information Technology, Noida<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Avisha Goyal<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Aces<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jaipur Engineering College and Research Centre, Jaipur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Ishan<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Algorithm Architects<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Maharaja Surajmal Institute of Technology_Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Yuvraj Gupta<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Alt F4<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SRM Institute of Science and Technology - Kattankulathur Campus<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Surajith Pranav<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">ALT+F4<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">University Institute of Engineering and Technology, Panjab University, Chandigarh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Amaan Kareem<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Ananya Gupta<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Indira Gandhi Delhi Technical University for Women, Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Ananya Gupta<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">ashtavakra<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">School of Computing &amp; Electrical Engineering<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Aditya<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Atul Jha<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Sant Longowal Institute of Engineering and Technology, Longowal<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Atul<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Baba Coders<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Maharaja Surajmal Institute of Technology_Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Punkil<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">BackSlachN<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jaipur Engineering College and Research Centre, Jaipur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Samridhi Sharma<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Binary Bats<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Maharaja Agrasen Institute of Technology, Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Diksha<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Binary Builders 01<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Institute of Engineering and Technology Devi Ahilya Vishwavidyalaya, Indore<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Dev Sahani<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Binary Quartet<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SRM Institute of Science and Technology - Kattankulathur Campus<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">LOVE TEWARI<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Bit Brains<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Pune Institute of Computer Technology, Pune<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Varad Vanga<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Bit Wizards<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Bhagwan Parshuram Institute of Technology, Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Anupam<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">BitBytes<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Army Institute of Technology, Pune<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Nitin Jhajharia<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">BitMavericks<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SRM Institute of Science and Technology - Modi Nagar&nbsp; Campus<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">AKSHAT<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">BlackInLatin<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Kurukshetra<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Rahul Siloniya<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Bulbul<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Jamshedpur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Indrani<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Byteforce<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jamia Millia Islamia, New Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">21BCS038 Musharraf<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Campus Coders<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Patna<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">ANMOL<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Code byte<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SRM Institute of Science and Technology - Modi Nagar&nbsp; Campus<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">ADITYA GUPTA<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Code Cartel<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Manipal University, Jaipur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Gokul Bansal<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Code commanders<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Jamshedpur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Rajni Singh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Code Crew<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Dwarkadas J Sanghvi College of Engineering, Mumbai<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Mahek<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Code Stormers<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Raipur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">5002 Aarif<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Code wizards<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SASTRA Deemed to be University, Thanjavur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Amarnath<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">codeKizen<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Maharaja Surajmal Institute of Technology_Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Kshitij<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">CoderZs<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Kurukshetra<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Vaibhav Chawla<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Codistics<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Meghalaya<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Sonam Bharti<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Combat Bots<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Maharaja Agrasen Institute of Technology, Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Mudit Gupta<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">commit<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Army Institute of Technology, Pune<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Karan<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Converse<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Maharaja Agrasen Institute of Technology, Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Sparsh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">CtrlShiftHack<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Raipur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Aman Jain<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Dark Coders<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Dwarkadas J Sanghvi College of Engineering, Mumbai<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jeet<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">DataDroids<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Vellore Institute of Technology - VIT Bhopal<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">AYUSH BHATT<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Debuggers<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Rajiv Gandhi Institute of Petroleum Technology Amethi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Kshitij<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Devanshu Chauhan<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Army Institute of Technology, Pune<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Devanshu Chauhan<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">DevOops<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Army Institute of Technology, Pune<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">ayush Bhadoria<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Devs don't React<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Bennett University, Greater Noida<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Manya Sharma<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Dhanvi Sharma<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">JECRC University, Jaipur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Dhanvi Sharma<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Doritos<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Vellore Institute of Technology - VIT Chennai<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Anushka<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Enigma-2.0<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Indian Institute of Information Technology, Pune<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Brijesh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Epsilon<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jamia Millia Islamia, New Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Mohd Siddiqul Haque<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Genesis<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Durgapur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Sahadat<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Git Gud Gang<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Vellore Institute of Technology - VIT Bhopal<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Harsh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">GitGat<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SRM Institute of Science and Technology - Kattankulathur Campus<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SOMANATHAN<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">GoodGuys<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Durgapur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">KIRTIKA<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Gurjit Sinder Singh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Dwarkadas J Sanghvi College of Engineering, Mumbai<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Gurjit<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Hack<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SRM Institute of Science and Technology - Kattankulathur Campus<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">YUVRAJ<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Hustle Squad<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Maharaja Surajmal Institute of Technology_Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Ayush Raj<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Hypothesis<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Institute of Engineering and Technology Devi Ahilya Vishwavidyalaya, Indore<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Animesh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Imposter<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Pune Institute of Computer Technology, Pune<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Shripad<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Inter-synergy<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">The LNM Institute of Information Technology, Jaipur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Pranjal<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">J0XX<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Mukesh Patel School of Technology Management and Engineering (B.Tech), Mumbai &amp; Shirpur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">rishit<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">JACS<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">PEC UNIVERSITY OF TECHNOLOGY<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jatin Kharbanda<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">JalJeera<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">International Institute of Information Technology, Naya Raipur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Parth<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jaskaran Baweja<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">The LNM Institute of Information Technology, Jaipur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jaskaran<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jellybean<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Vellore Institute of Technology - VIT Chennai<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Eshaan Joshi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jolly Joseph<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">IIEST, Shibpur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Hamsa<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Little bits<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Bharati Vidyapeeth's College of Engineering, Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Kashish<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Merge Conflict<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Dwarkadas J Sanghvi College of Engineering, Mumbai<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Deep<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">MLE<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Indian Institute of Information Technology, Agartala<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Azmat Alam<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Momos Chutney<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">PEC UNIVERSITY OF TECHNOLOGY<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Kabir<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">NeverLose<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Manipal University, Jaipur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Animesh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">NPCD<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Thapar Institute of Engineering and Technology, Patiala<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Pari Gujral<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">PHOENIX<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Vellore Institute of Technology - VIT Amravati<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">MAYALURI ANUSHA<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Proformers<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">PEC UNIVERSITY OF TECHNOLOGY<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">RAJAT<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Python tech<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Kurukshetra<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">vansh agarwal<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Pythoners<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Dwarkadas J Sanghvi College of Engineering, Mumbai<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Pravin Nag<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Quad<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">IIEST, Shibpur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Satvik<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Quadruple<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Institute of Engineering and Technology Devi Ahilya Vishwavidyalaya, Indore<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Rudraksh Ranade<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Quasar<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Dr B R Ambedkar National Institute of Technology Jalandhar<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Ayush<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Ram Bhakt<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Vellore Institute of Technology - VIT Chennai<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Devansh Tewari<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">ScaleCrafters<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Army Institute of Technology, Pune<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Shantanu Rajmane<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SHIP<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Army Institute of Technology, Pune<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Sahil Kamate<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Shubhodip Pal<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Durgapur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Shubhodip Pal<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Skill Issue<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Jamshedpur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Pragati<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Sleepy Coders<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">University Institute of Engineering and Technology, Panjab University, Chandigarh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Aryan Singh Dhiman<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Spam-Bytes<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jaipur Engineering College and Research Centre, Jaipur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Mudit<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SPD.nvm<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Dwarkadas J Sanghvi College of Engineering, Mumbai<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Husain<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">StackOverFlow<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">IIEST, Shibpur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Aninda Nath<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">starwars<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jaypee University of Information Technology, Solan<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Sarthak Kurothe<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SYNTAX SQUAD<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">The LNM Institute of Information Technology, Jaipur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Vishal<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Team Pegasus<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Guru Gobind Singh Indraprastha University, Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Adamya<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Team Rocket<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Fr C Rodrigues Institute of Technology, Navi Mumbai<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Aman<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Team Unknowns<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">KJ Somaiya College of Engineering, Mumbai<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Aditya<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Tech Divas<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">GL Bajaj Institute of Technology and Management<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Aadhyaa<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Tech Elite<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">IIEST, Shibpur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Shivam Raj<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">TECH INNOVATORS<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SRM Institute of Science and Technology - Kattankulathur Campus<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Ankit Singh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Tech_geeks<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jadavpur University, Kolkata<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">mudassir Parvez<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Techmates<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Indian Institute of Information Technology, Sri City<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SUSRITHA<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Technoverts<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jaypee Institute of Information Technology, Noida<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Aayushi Garg<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">TechPhantoms<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Bhagwan Parshuram Institute of Technology, Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Jaskirat Singh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">TechQuad<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Maharaja Agrasen Institute of Technology, Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Aditya<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Techtonics<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Arunachal Pradesh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Keshav<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Techverse<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Maharaja Surajmal Institute of Technology_Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Sania Noor<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Tecz<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SASTRA Deemed to be University, Thanjavur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Sivagami Thiagarajan<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Thapar<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Thapar Institute of Engineering and Technology, Patiala<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Deeksha Goel<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">The coders<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Indian Institute of Information Technology Dharwad<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Godara Deepaksingh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">The Cosmos<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Raipur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Harsh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">The Shinigamis<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Maharaja Surajmal Institute of Technology_Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Harshit Sachdeva<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">The South Campus Crew<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">University Institute of Engineering and Technology, Panjab University, Chandigarh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Madhur Saini<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">The Squad<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SASTRA Deemed to be University, Thanjavur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Tulip Raaj K<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">TRINITY NEXUS<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SRM Institute of Science and Technology - Kattankulathur Campus<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SUBHAM<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Vanar Sena<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Graphic Era University<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Ayush Negi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">vortex<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Institute of Engineering and Technology Devi Ahilya Vishwavidyalaya, Indore<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Rishabh<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">WebGeeksters<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Maharaja Surajmal Institute of Technology_Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Mridul.<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">WeMakeCode<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">JECRC University, Jaipur<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Mridul<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">WuShang Clan<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Bhagwan Parshuram Institute of Technology, Delhi<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Vaibhav<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">ZCODER<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">SRM Institute of Science and Technology - Kattankulathur Campus<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">AKASH<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Zenith_4<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Institute of Engineering and Technology Devi Ahilya Vishwavidyalaya, Indore<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Meghana Maheshwari<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:14.5pt">
<td width="147" nowrap="" style="width:110.25pt;border:none;border-left:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Zink<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Kurukshetra<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border:none;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:14.5pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Nikhil Sri Krishna L<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
<tr style="height:15.0pt">
<td width="147" nowrap="" style="width:110.25pt;border-top:none;border-left:solid windowtext 1.0pt;border-bottom:solid windowtext 1.0pt;border-right:none;padding:0in 5.4pt 0in 5.4pt;height:15.0pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">ZippyRejects<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="565" nowrap="" style="width:423.4pt;border:none;border-bottom:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:15.0pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">National Institute of Technology Kurukshetra<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td><td width="162" nowrap="" style="width:121.4pt;border-top:none;border-left:none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;padding:0in 5.4pt 0in 5.4pt;height:15.0pt">
<p class="MsoNormal" align="center" style="margin-bottom:0in;text-align:center;line-height:normal">
<span><span style="font-size:10.0pt;color:black">Shakeeb<u></u><u></u></span></span></p>
</td>
<td><span></span>
</td></tr>
</tbody>
</table>
'''

# Count the number of rows in the table
number_of_rows = count_table_rows(html_string)
print(f'Number of rows in the table: {number_of_rows}')

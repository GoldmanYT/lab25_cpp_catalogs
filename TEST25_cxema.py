from PIL import Image, ImageDraw, ImageFont
from math import sin, cos, pi


font = ImageFont.truetype("arial.ttf", 11)
W, H = 1080, 1920
x0, y0 = 20, 10
dx, dy = 30, 20
cx, cy = W // 2, H // 2
N = 95
line_color = 0, 0, 0, 255
image = Image.new('RGBA', (W, H), (255, 255, 255, 255))
draw = ImageDraw.Draw(image)

P = []
for i in range(N):
    draw.rectangle((x0, y0 + i * dy, x0 + dx, y0 + (i + 1) * dy),
                   outline=line_color)
    x, y = x0 + dx // 2, y0 + i * dy + dy // 2
    x += 15
    P.append((x, y))

x0, y0 = W - dx - 20, 10
s = 'S=SQRT(P*(P-A)*(P-B)*(P-C))(A+B+C)/2'
P1 = []
P2 = []
for i in range(len(s)):
    draw.rectangle((x0, y0 + i * dy, x0 + dx, y0 + (i + 1) * dy),
                   outline=line_color)
    x, y = x0 + dx // 2, y0 + i * dy + dy // 2
    draw.text((x, y), s[i],
              fill=line_color, anchor='mm', font=font)
    x -= 15
    draw.line((P[i], (x, y)), fill=line_color)
    if i < 27:
        P1.append((x, y))
    else:
        P2.append((x, y))
P3 = []
t = '(A+B+C)/2'
for k in range(27):
    if s[k] != 'P':
        P3.append(P1[k])
    else:
        for l in range(9):
            P3.append(P2[l])
for i in range(len(s), N):
    x, y = P3[i - len(s)]
    draw.line((P[i], (x, y)), fill=line_color)

x0, y0 = 7, 10
for i, r in enumerate((0, 27, 36), 1):
    x, y = x0, y0 + r * dy + dy // 2
    draw.text((x, y), f'P{i}',
              fill=line_color, anchor='lm', font=font)

draw.text((cx // 2, 2), 'Статическая память',
          fill=line_color, anchor='mt', font=font)
draw.text((cx + cx // 2, 2), 'Динамическая память',
          fill=line_color, anchor='mt', font=font)

x0, y0 = cx, 10
for i in range(N):
    if i % 2 == 0:
        draw.line((x0, y0 + dy * i, x0, y0 + dy * (i + 1)),
                  fill=line_color)

image.save('res.png')

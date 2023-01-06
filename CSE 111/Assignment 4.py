
import tkinter as tk
import random

def main():
    # The width and height of the scene window.
    width = 800
    height = 500

    # Create the Tk root object.
    root = tk.Tk()
    root.geometry(f"{width}x{height}")
    

    # Create a Frame object.
    frame = tk.Frame(root)
    frame.master.title("Scene")
    frame.pack(fill=tk.BOTH, expand=1)

    # Create a canvas object that will draw into the frame.
    canvas = tk.Canvas(frame)
    canvas.pack(fill=tk.BOTH, expand=1)

    # Call the draw_scene function.
    draw_scene(canvas, 0, 0, width-1, height-1)

    root.mainloop()

def draw_scene(canvas, scene_left, scene_top, scene_right, scene_bottom):
    draw_sky(canvas)
    draw_clouds(canvas)
    draw_ground(canvas)
    draw_grass(canvas)
    draw_pond(canvas)
    draw_tree(canvas)
    draw_house(canvas)
    draw_road(canvas)
    draw_city(canvas)
    
def draw_sky(canvas):
    #background
    canvas.create_rectangle(0,0,799,499, fill = "#10006C", outline = "#10006C")
    #stars
    count = 1
    while count < 70:
        xray = random.randint(0,799)
        zulu = random.randint(0,300)
        canvas.create_line(xray,zulu,xray,zulu + 10, fill = "white")
        canvas.create_line(xray - 4, zulu + 5, xray + 5, zulu + 5, fill = "white")
        count += 1
    #moon base
    canvas.create_oval(50, 50, 100, 100, fill = "#E4E4E4", outline = "#E4E4E4")

    count = 1
    while count < 5:
        color_list = ["#888888", "#6B6B6B", "#A1A1A1"]
        zulu = random.randint(63,87)
        xray = random.randint(63,87)
        canvas.create_oval(zulu,xray,zulu + 12,xray + 12, fill = random.choice(color_list))
        count += 1      
def draw_clouds(canvas):
    #alpha
    canvas.create_oval(170,30,290,110, fill = "#B1B1B1", outline = "#B1B1B1")
    #alpha side top
    canvas.create_oval(185,20,245,65, fill = "#B1B1B1", outline = "#B1B1B1")
    #alpha left bottom
    canvas.create_oval(150,60,200,100, fill = "#B1B1B1", outline = "#B1B1B1")
    #alpha right
    canvas.create_oval(270,50,330,90, fill = "#B1B1B1", outline = "#B1B1B1")
    #bravo
    canvas.create_oval(550,20,650,80, fill = "#B1B1B1", outline = "#B1B1B1")
    #bravo right
    canvas.create_oval(600,35,700,95, fill = "#B1B1B1", outline = "#B1B1B1")
    #bravo left
    canvas.create_oval(500,50,560,90, fill = "#B1B1B1", outline = "#B1B1B1")
def draw_ground(canvas):
    canvas.create_rectangle(0,300,799,499, fill = "#B96100", outline = "#B96100")
def draw_grass(canvas):

    count = 1
    x = 10
    y = 315
    z = 305
    while count <= 25:
        x += 30
        #y += 20
        #z += 20
        canvas.create_line(x,y,x,z, fill = "#4db81f")
        canvas.create_line(x,y,x + 5,z, fill = "#4db81f")
        canvas.create_line(x,y,x - 5,z, fill = "#4db81f")
        count += 1
    
    count = 1
    x = 0
    y = 315
    z = 305

    while count <= 26:
        x += 30
        y += 20
        z += 20
        canvas.create_line(x,y,x,z, fill = "#4db81f")
        canvas.create_line(x,y,x + 5,z, fill = "#4db81f")
        canvas.create_line(x,y,x - 5,z, fill = "#4db81f")
        y -= 20
        z -= 20
        count += 1

    count = 1
    x = 20
    y = 315
    z = 305

    while count <= 25:
        x += 30
        y += 40
        z += 40
        canvas.create_line(x,y,x,z, fill = "#4db81f")
        canvas.create_line(x,y,x + 5,z, fill = "#4db81f")
        canvas.create_line(x,y,x - 5,z, fill = "#4db81f")
        y -= 40
        z -= 40
        count += 1

    count = 1
    x = 10
    y = 315
    z = 305

    while count <= 25:
        x += 30
        y += 60
        z += 60
        canvas.create_line(x,y,x,z, fill = "#4db81f")
        canvas.create_line(x,y,x + 5,z, fill = "#4db81f")
        canvas.create_line(x,y,x - 5,z, fill = "#4db81f")
        y -= 60
        z -= 60
        count += 1

    count = 1
    x = 0
    y = 315
    z = 305

    while count <= 26:
        x += 30
        y += 80
        z += 80
        canvas.create_line(x,y,x,z, fill = "#4db81f")
        canvas.create_line(x,y,x + 5,z, fill = "#4db81f")
        canvas.create_line(x,y,x - 5,z, fill = "#4db81f")
        y -= 80
        z -= 80
        count += 1
    
    count = 1
    x = 20
    y = 315
    z = 305

    while count <= 25:
        x += 30
        y += 100
        z += 100
        canvas.create_line(x,y,x,z, fill = "#4db81f")
        canvas.create_line(x,y,x + 5,z, fill = "#4db81f")
        canvas.create_line(x,y,x - 5,z, fill = "#4db81f")
        y -= 100
        z -= 100
        count += 1
    
    count = 1
    x = 10
    y = 315
    z = 305

    while count <= 25:
        x += 30
        y += 120
        z += 120
        canvas.create_line(x,y,x,z, fill = "#4db81f")
        canvas.create_line(x,y,x + 5,z, fill = "#4db81f")
        canvas.create_line(x,y,x - 5,z, fill = "#4db81f")
        y -= 120
        z -= 120
        count += 1

    count = 1
    x = 0
    y = 315
    z = 305

    while count <= 26:
        x += 30
        y += 140
        z += 140
        canvas.create_line(x,y,x,z, fill = "#4db81f")
        canvas.create_line(x,y,x + 5,z, fill = "#4db81f")
        canvas.create_line(x,y,x - 5,z, fill = "#4db81f")
        y -= 140
        z -= 140
        count += 1
    
    count = 1
    x = 20
    y = 315
    z = 305

    while count <= 25:
        x += 30
        y += 160
        z += 160
        canvas.create_line(x,y,x,z, fill = "#4db81f")
        canvas.create_line(x,y,x + 5,z, fill = "#4db81f")
        canvas.create_line(x,y,x - 5,z, fill = "#4db81f")
        y -= 160
        z -= 160
        count += 1
def draw_pond(canvas):
    canvas.create_oval(330,350,430,410, fill = "#0061C9")
def draw_tree(canvas):
    #shrub 3
    canvas.create_oval(320,315,345,340, fill = "#7CA420")
    #tree 1
    canvas.create_rectangle(300,250,330,350, fill = "#7D3F00", outline = "#7D3F00")
    canvas.create_polygon(315,50,250,250,380,250, fill = "#266001", outline = "#266001")
    #shrub 5
    canvas.create_oval(455,280,480,310, fill = "#7CA420")
    #tree 2
    canvas.create_rectangle(450,220,470,320, fill = "#7D3F00", outline = "#7D3F00")
    canvas.create_polygon(460,20,410,260,510,260, fill = "#266001", outline = "#266001")
    #shrub 1
    canvas.create_oval(290,330,315,360, fill = "#7CA420")
    #shrub 2
    canvas.create_oval(310,335,335,365, fill = "#7CA420")
    #shrub 4
    canvas.create_oval(435,305,460,335, fill = "#7CA420")
    #leaves
    count = 1
    while count < 40:
        color_list = ["#5CFF20", "#C8FF40", "#608700"]
        zulu = random.randint(50,250)
        if zulu <= 100:
            xray = random.randint(310,320)
        if zulu <= 150 and zulu > 100:
            xray = random.randint(295,335)
        if zulu <= 200 and zulu > 150:
            xray = random.randint(280,350)
        if zulu <= 250 and zulu > 200:
            xray = random.randint(270,360)
        canvas.create_polygon(xray - 5,zulu,xray + 5,zulu, xray, zulu + 10, fill = random.choice(color_list))
        count += 1
    #leaves two
    count = 1
    while count < 40:
        color_list = ["#5CFF20", "#C8FF40", "#608700"]
        zulu = random.randint(30,260)
        if zulu <= 100:
            xray = random.randint(455,465)
        if zulu <= 150 and zulu > 100:
            xray = random.randint(445,475)
        if zulu <= 200 and zulu > 150:
            xray = random.randint(435,485)
        if zulu <= 260 and zulu > 200:
            xray = random.randint(420,500)
        canvas.create_polygon(xray - 5,zulu,xray + 5,zulu, xray, zulu + 10, fill = random.choice(color_list))
        count += 1
    #alpha = randint()
def draw_house(canvas):
    canvas.create_rectangle(35,240,200,400, fill = "#F7FFA6")
    canvas.create_arc(150,320,250,480, fill = "#AB7B00")
    canvas.create_polygon(25,240,210,240,117,120, fill = "#B70000")
    canvas.create_rectangle(97,340,132,400, fill = "#B70000")
    canvas.create_oval(50,250,95,295, fill = "#A0FFF5")
    canvas.create_oval(135,250,180,295, fill = "#A0FFF5")

    count = 1
    x = 20
    y = 390
    z = 35
    a = 440

    while count <= 30:
        x += 17
        z += 17
        canvas.create_rectangle(x,y,z,a, fill = "#ECB125")
        count += 1
def draw_road(canvas):
    canvas.create_polygon(580,499,680,499,660,300,600,300, fill = "#534646")
    canvas.create_line(630,499,630,480, fill = "white")
    canvas.create_line(630,470,630,450, fill = "white")
    canvas.create_line(630,440,630,420, fill = "white")
    canvas.create_line(630,410,630,390, fill = "white")
    canvas.create_line(630,380,630,360, fill = "white")
    canvas.create_line(630,350,630,330, fill = "white")
    canvas.create_line(630,320,630,300, fill = "white")
def draw_city(canvas):
    canvas.create_rectangle(550,250,570,300, fill = "#444444")
    canvas.create_rectangle(570,220,595,300, fill = "#696969")
    canvas.create_rectangle(595,235,615,300, fill = "#414141")
    canvas.create_rectangle(615,205,630,300, fill = "#A0A0A0")
    canvas.create_rectangle(630,270,665,300, fill = "#292929")
    canvas.create_rectangle(665,255,685,300, fill = "#828282")
    canvas.create_rectangle(685,215,700,300, fill = "#C1C1C1")
    canvas.create_rectangle(700,235,730,300, fill = "#5A5A5A")

main()

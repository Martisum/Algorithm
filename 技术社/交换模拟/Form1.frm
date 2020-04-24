VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   6660
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   11595
   LinkTopic       =   "Form1"
   ScaleHeight     =   6660
   ScaleWidth      =   11595
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   1815
      Left            =   480
      TabIndex        =   2
      Top             =   2880
      Width           =   4215
   End
   Begin VB.TextBox Text2 
      Height          =   1095
      Left            =   2160
      TabIndex        =   1
      Text            =   "Text2"
      Top             =   1200
      Width           =   2055
   End
   Begin VB.TextBox Text1 
      Height          =   1095
      Left            =   480
      TabIndex        =   0
      Text            =   "Text1"
      Top             =   1200
      Width           =   1455
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Function swap(x As Integer, y As Integer)
    Dim t As Integer
    t = x: x = y: y = t
End Function
Private Sub Command1_Click()
    Dim a As Integer
    Dim b As Integer
    a = 3: b = 4
    swap a, b
    Text1.Text = a
    Text2.Text = b
End Sub

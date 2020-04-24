VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4530
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   7740
   LinkTopic       =   "Form1"
   ScaleHeight     =   4530
   ScaleWidth      =   7740
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.TextBox Text1 
      Height          =   1335
      Left            =   1200
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   2040
      Width           =   2895
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   1095
      Left            =   840
      TabIndex        =   0
      Top             =   240
      Width           =   2655
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim a As String: Dim b As Integer
a = "123"
b = Asc(Mid(a, 1, 1)) - 48
Text1.Text = Val(b)
End Sub


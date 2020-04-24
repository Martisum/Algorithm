VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   2160
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   1800
   LinkTopic       =   "Form1"
   ScaleHeight     =   2160
   ScaleWidth      =   1800
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox Text1 
      Height          =   1335
      Left            =   120
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   720
      Width           =   1575
   End
   Begin VB.CommandButton Command1 
      Caption         =   "呵呵"
      Height          =   495
      Left            =   240
      TabIndex        =   0
      Top             =   120
      Width           =   1455
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim init As Integer
Sub form_load()
    MsgBox ("将执行赋值语句！在text1读入，单击按钮执行")
End Sub
Function judge(n As Integer)
    If n > 1 And n <= 5 Then
        MsgBox ("小于一大于五")
    ElseIf n > 5 And n <= 10 Then
        MsgBox ("大于五小于十")
    End If
End Function
Function forcycle(n As Integer)
    For n = 5 To 10 Step 1
        MsgBox (Str(n))
    Next n
End Function
Function whilecycle(n As Integer)
    Do While n <= 10
        n = n + 1
        MsgBox (Str(n))
    Loop
End Function
Function assignment(n As Integer) '赋值函数
    Dim a As Integer
    a = n
    Text1.Text = a
End Function
Private Sub Command1_Click()
    init = Text1.Text
    assignment (init)
    MsgBox ("将执行while语句！")
    whilecycle (init)
    MsgBox ("将执行for语句！")
    forcycle (init)
    MsgBox ("将执行if语句！")
    judge (init)
    MsgBox ("结束！")
End Sub

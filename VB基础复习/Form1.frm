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
   StartUpPosition =   3  '����ȱʡ
   Begin VB.TextBox Text1 
      Height          =   1335
      Left            =   120
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   720
      Width           =   1575
   End
   Begin VB.CommandButton Command1 
      Caption         =   "�Ǻ�"
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
    MsgBox ("��ִ�и�ֵ��䣡��text1���룬������ťִ��")
End Sub
Function judge(n As Integer)
    If n > 1 And n <= 5 Then
        MsgBox ("С��һ������")
    ElseIf n > 5 And n <= 10 Then
        MsgBox ("������С��ʮ")
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
Function assignment(n As Integer) '��ֵ����
    Dim a As Integer
    a = n
    Text1.Text = a
End Function
Private Sub Command1_Click()
    init = Text1.Text
    assignment (init)
    MsgBox ("��ִ��while��䣡")
    whilecycle (init)
    MsgBox ("��ִ��for��䣡")
    forcycle (init)
    MsgBox ("��ִ��if��䣡")
    judge (init)
    MsgBox ("������")
End Sub

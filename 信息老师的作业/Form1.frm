VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3030
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   ScaleHeight     =   3030
   ScaleWidth      =   4560
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command2 
      Caption         =   "Command2"
      Height          =   375
      Left            =   1440
      TabIndex        =   2
      Top             =   2400
      Width           =   1335
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   1680
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   1320
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   495
      Left            =   1680
      TabIndex        =   0
      Top             =   1320
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command2_Click()
Private Sub Command2_Click()    '去重
s1 = Text1.Text
s2 = Mid(s1, 1, 1)
For i = 1 To Len(s1)
    ch = Mid(s1, i, 1)
    For n = 1 To Len(s2)
        If Mid(s2, n, 1) <> ch Then s2 = s2 + ch
    Next n
Next i
Text4.Text = s2
End Sub
钱俊彦我这个s2输出后一直非常长不知道为什么

End Sub

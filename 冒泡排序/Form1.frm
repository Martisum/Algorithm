VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4830
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   2145
   LinkTopic       =   "Form1"
   ScaleHeight     =   4830
   ScaleWidth      =   2145
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command1 
      Caption         =   "排序！"
      Height          =   1215
      Left            =   120
      TabIndex        =   1
      Top             =   120
      Width           =   1815
   End
   Begin VB.ListBox List1 
      Height          =   2760
      Left            =   120
      TabIndex        =   0
      Top             =   1680
      Width           =   1935
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
Dim n As Integer: Dim data(1 To 1000) As Integer
Dim i As Integer: Dim j As Integer: Dim t As Integer
n = InputBox("输入你要排序的数字个数")
For i = 1 To n
    data(i) = InputBox("输入数据")
Next i
For i = 1 To n - 1
   For j = 1 To n - 1
        If data(j) > data(j + 1) Then
            swap data(j), data(j + 1)
        End If
   Next j
Next i
For i = 1 To n
    List1.AddItem data(i)
Next i
End Sub

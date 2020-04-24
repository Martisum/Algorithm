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
Function max(x As Integer, y As Integer) As Integer
If x >= y Then
    max = x
ElseIf x < y Then
    max = y
End If
End Function
Private Sub Command1_Click()
Dim n As Integer: Dim data(1 To 1000) As Integer
Dim i As Integer: Dim j As Integer
Dim book(1 To 1000) As Integer
n = InputBox("输入你要排序的数字个数")
For i = 1 To n
    data(i) = InputBox("输入数据")
Next i
For i = 1 To n
    book(i) = 0
Next i
For i = 1 To n
    book(data(i)) = book(data(i)) + 1
Next i
Dim maxs As Integer: Dim t As Integer
maxs = 0: t = 1
For i = 1 To n
    maxs = max(maxs, data(i))
Next i
For i = 1 To maxs
    If book(i) <> 0 Then
        data(t) = i: t = t + 1
    End If
Next i
For i = 1 To n
    List1.AddItem data(i)
Next i
End Sub

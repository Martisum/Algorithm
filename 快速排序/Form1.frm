VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   6255
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   3435
   LinkTopic       =   "Form1"
   ScaleHeight     =   6255
   ScaleWidth      =   3435
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton command1 
      Caption         =   "排序"
      Height          =   2175
      Left            =   2760
      TabIndex        =   3
      Top             =   840
      Width           =   615
   End
   Begin VB.ListBox List1 
      Height          =   4560
      Left            =   240
      TabIndex        =   2
      Top             =   840
      Width           =   2295
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   1680
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   120
      Width           =   1455
   End
   Begin VB.Label Label1 
      Caption         =   "共有几个数据？"
      Height          =   375
      Left            =   120
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
Dim a(1 To 101) As Integer
Dim n As Integer
Function swap(a As Integer, b As Integer)
    Dim t As Integer
    If a >= b Then
        t = a: a = b: b = t
    End If
End Function
Function quicksort(l As Integer, r As Integer)
    Dim flag As Integer: Dim tl As Integer: Dim tr As Integer
    tl = l: tr = r: flag = r
    
    Do While tl < tr
        Do While a(tl) <= a(flag) And tl < tr
            tl = tl + 1
        Loop
        
        Do While a(tr) >= a(flag) And tl < tr
            tr = tr - 1
        Loop
        If a(tl) > a(tr) Then swap a(tl), a(tr)
    Loop
    swap a(tl), a(flag)
    flag = tl
    
    If l < flag - 1 Then quicksort l, flag - 1
    If flag + 1 < r Then quicksort flag + 1, r
End Function
Private Sub command1_Click()
    Dim i As Integer: Dim j As Integer
    n = Text1.Text
    For i = 1 To n
        a(i) = InputBox("请输入数值")
    Next i
    quicksort 1, n
    For i = 1 To n
        List1.AddItem a(i)
    Next i
End Sub

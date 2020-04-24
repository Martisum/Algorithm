VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3855
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   3060
   LinkTopic       =   "Form1"
   ScaleHeight     =   3855
   ScaleWidth      =   3060
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command1 
      Caption         =   "查找"
      Height          =   540
      Left            =   1680
      TabIndex        =   8
      Top             =   3240
      Width           =   1215
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   1680
      TabIndex        =   7
      Text            =   "Text3"
      Top             =   2640
      Width           =   1095
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   1680
      TabIndex        =   5
      Text            =   "Text2"
      Top             =   1560
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      BackColor       =   &H0000FFFF&
      Height          =   375
      Left            =   1800
      TabIndex        =   3
      Text            =   "Text1"
      Top             =   600
      Width           =   1095
   End
   Begin VB.ListBox List1 
      Height          =   3120
      Left            =   120
      TabIndex        =   1
      Top             =   600
      Width           =   1575
   End
   Begin VB.Label Label4 
      Caption         =   "查找的次数"
      Height          =   255
      Left            =   1680
      TabIndex        =   6
      Top             =   2160
      Width           =   1095
   End
   Begin VB.Label Label3 
      Caption         =   "查找的结果"
      Height          =   255
      Left            =   1800
      TabIndex        =   4
      Top             =   1200
      Width           =   975
   End
   Begin VB.Label Label2 
      Caption         =   "输入查找键"
      Height          =   375
      Left            =   1800
      TabIndex        =   2
      Top             =   120
      Width           =   975
   End
   Begin VB.Label Label1 
      Caption         =   "数组d中的数据"
      Height          =   375
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim d(1 To 128) As Integer
Dim nc As Integer
Function adj(a As String, n As Integer) As String
    Dim sa As String
    na = Len(a): sa = a
    For i = 1 To n - na
        sa = " " + sa
    Next i
    adj = sa
End Function
Sub form_load()
    Dim dv As Integer
    dv = 2 '随机产生128个值递增的整数存到d中
    For i = 1 To 128
        dv = dv + Fix((Timer() Mod 67 + 13) * Rnd()) + 1
        d(i) = dv
    Next i
    For i = 1 To 128 '在list1中显示所有数据及下标
        List1.AddItem adj(Str(i), 3) + ":" + adj(Str(d(i)), 6)
    Next i
End Sub
Function search(key As Integer) As Integer '核心代码
    i = 1: j = 128: nc = 0
    Do While i <= j
        nc = nc + 1
        m = Fix((i + j) / 2) '计算中点位置
        If d(m) = key Then
            search = m: Exit Function
        End If
        If key < d(m) Then
            j = m - 1
        Else
            i = m + 1
        End If
    Loop
    search = 0
End Function
Private Sub Command1_Click()
    Dim key As Integer
    key = Val(Text1.Text)
    nr = search(key)
    If nr > 0 Then
        Text2.Text = "在d(" + Str(nr) + ")中"
    Else
        Text2.Text = "找不到"
    End If
    Text3.Text = Str(nc)
End Sub
Private Sub Text1_Click()
    Text1.Text = " ": Text2.Text = " ": Text3.Text = " "
End Sub

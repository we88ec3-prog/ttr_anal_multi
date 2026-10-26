
void FUN_0069b3a0(void)

{
  void *_Dst;
  int *in_EAX;
  int iVar1;
  int unaff_ESI;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105b9) goto LAB_0069b3d8;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_0069b3d8:
  *(int *)(unaff_ESI + 0x120) = in_EAX[5];
  FUN_0075cd30(*(undefined4 *)(unaff_ESI + 0x94));
  (**(code **)(**(int **)(unaff_ESI + 0x94) + 200))();
  _Dst = *(void **)(unaff_ESI + 0x164);
  if (_Dst != *(void **)(unaff_ESI + 0x168)) {
    FID_conflict__memcpy(_Dst,*(void **)(unaff_ESI + 0x168),0);
    *(void **)(unaff_ESI + 0x168) = _Dst;
  }
  (**(code **)(**(int **)(unaff_ESI + 0xbc) + 0x90))
            (*(int *)(unaff_ESI + 0x164) != *(int *)(unaff_ESI + 0x168));
  FUN_0069a1c0(unaff_ESI);
  FUN_0069a050(unaff_ESI);
  FUN_00699b20(unaff_ESI);
  return;
}


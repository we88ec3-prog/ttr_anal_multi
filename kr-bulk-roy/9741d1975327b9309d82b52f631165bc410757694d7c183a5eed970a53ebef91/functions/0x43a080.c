
void FUN_0043a080(void)

{
  int iVar1;
  undefined4 in_ECX;
  int *unaff_ESI;
  undefined2 local_8;
  undefined1 local_6;
  undefined1 uStack_5;
  
  uStack_5 = (undefined1)((uint)in_ECX >> 0x18);
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105b9) goto LAB_0043a0b2;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0043a0b2:
  iVar1 = unaff_ESI[5];
  if ((-1 < iVar1) && (iVar1 < 3)) {
    _local_8 = CONCAT12((char)iVar1,0xfd);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,3);
    }
  }
  return;
}


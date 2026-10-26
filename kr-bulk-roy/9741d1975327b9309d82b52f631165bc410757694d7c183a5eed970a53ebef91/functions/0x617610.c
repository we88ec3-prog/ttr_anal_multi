
void FUN_00617610(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int *in_ECX;
  char cVar4;
  int *piVar5;
  int unaff_EDI;
  char cStack_19;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (in_ECX == (int *)0x0) {
LAB_00617669:
    in_ECX = (int *)0x0;
  }
  else {
    iVar2 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    if (iVar2 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_00617669;
    }
  }
  piVar5 = (int *)in_ECX[6];
  if (piVar5 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar5 + 4))();
    if (iVar2 == 0x12d) goto LAB_00617694;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar5 = (int *)0x0;
LAB_00617694:
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    uStack_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    uStack_c = 0xffffffff;
  }
  if (((*(byte *)(unaff_EDI + 0x10c) < 10) &&
      (iVar2 = (uint)*(byte *)(unaff_EDI + 0x10c) * 0x210 + DAT_00f94304,
      *(int *)(iVar2 + 0x5c) != 0)) && (iVar2 != 0)) {
    pcVar3 = (char *)(iVar2 + 500);
  }
  else {
    pcVar3 = (char *)0x0;
  }
  if ((piVar5 != (int *)0x0) && (pcVar3 != (char *)0x0)) {
    cStack_19 = pcVar3[1];
    cVar1 = *(char *)((int)piVar5 + 0x261);
    cVar4 = cVar1;
    if ((*pcVar3 != '\0') && (*(int *)(unaff_EDI + 0x110) != 0)) {
      cVar4 = *pcVar3;
      cStack_19 = cVar1;
    }
    iVar2 = FUN_00617880(1);
    if (iVar2 == 0) {
      FUN_00414680();
      FUN_004a4690(*(undefined1 *)(unaff_EDI + 0x10c),cVar4,cStack_19);
    }
  }
  ExceptionList = local_14;
  return;
}


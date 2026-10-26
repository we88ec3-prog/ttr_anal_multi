
void FUN_00410d50(void)

{
  char *pcVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  uint uVar4;
  short sVar5;
  int *in_EAX;
  int iVar6;
  int iVar7;
  int unaff_ESI;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if (in_EAX != (int *)0x0) {
    iVar6 = (**(code **)(*in_EAX + 4))();
    if (iVar6 == 0x105bf) goto LAB_00410d88;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_00410d88:
  local_10 = in_EAX[5];
  iVar6 = in_EAX[6];
  sVar5 = (short)in_EAX[7];
  local_c = 99;
  if (0 < *(int *)(unaff_ESI + 0x148)) {
    local_8 = *(int *)(unaff_ESI + 0x138);
    FUN_0053f8a0();
    FUN_0082ef00(local_8 + 0xc);
    if (local_8 == *(int *)(unaff_ESI + 0x118)) {
      local_8 = 0;
    }
    else {
      local_8 = (uint)*(byte *)(*(int *)(local_8 + 0x10) + 7);
    }
    iVar6 = iVar6 + 5;
    if (iVar6 <= (int)local_8) {
      do {
        iVar7 = FUN_00411b30(unaff_ESI,iVar6);
        if (iVar7 <= iVar6) goto LAB_00410eab;
        if (iVar7 - iVar6 < local_c) {
          local_c = iVar7 - iVar6;
        }
        iVar6 = iVar6 + 5;
      } while (iVar6 <= (int)local_8);
    }
    FUN_0082ef00(&local_10);
    FUN_0082ef00(&local_10);
    uVar4 = local_8;
    if (local_8 != *(uint *)(unaff_ESI + 0x118)) {
      if (local_c < sVar5) {
        sVar5 = (short)local_c;
      }
      *(int *)(unaff_ESI + 0x148) = *(int *)(unaff_ESI + 0x148) - (int)sVar5;
      pcVar1 = (char *)(*(int *)(local_8 + 0x10) + 6);
      *pcVar1 = *pcVar1 - (char)sVar5;
      *(char *)(local_14 + 0x10) = *(char *)(local_14 + 0x10) - (char)sVar5;
      if (*(char *)(local_14 + 0x10) == '\0') {
        FUN_007b6890(unaff_ESI + 0x134,&local_14,local_14);
      }
      iVar6 = *(int *)(unaff_ESI + 0x110);
      uVar2 = *(undefined1 *)(unaff_ESI + 0x144);
      uVar3 = *(undefined1 *)(unaff_ESI + 0x145);
      *(undefined4 *)(iVar6 + 0x108) = *(undefined4 *)(uVar4 + 0x10);
      *(undefined1 *)(iVar6 + 0x104) = uVar3;
      *(undefined1 *)(iVar6 + 0x105) = uVar2;
      FUN_004704c0(iVar6);
    }
LAB_00410eab:
    FUN_004107f0(unaff_ESI);
  }
  return;
}


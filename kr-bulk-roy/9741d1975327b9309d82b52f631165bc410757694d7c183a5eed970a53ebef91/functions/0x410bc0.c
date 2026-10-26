
void FUN_00410bc0(int param_1)

{
  char *pcVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  int *in_EAX;
  int iVar5;
  undefined4 uVar6;
  short sVar7;
  int local_18;
  int local_14;
  int local_c [2];
  
  if (in_EAX != (int *)0x0) {
    iVar5 = (**(code **)(*in_EAX + 4))();
    if (iVar5 == 0x105bf) goto LAB_00410bfc;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_00410bfc:
  local_c[0] = in_EAX[5];
  sVar7 = (short)in_EAX[7];
  iVar5 = *(int *)(param_1 + 0x14c);
  iVar4 = in_EAX[6];
  if ((iVar4 <= iVar5) && (FUN_0082ef00(local_c), local_14 != *(int *)(param_1 + 0x118))) {
    if ((*(int *)(param_1 + 0x154) < sVar7 + iVar5) &&
       (sVar7 = *(short *)(param_1 + 0x154) - (short)iVar5, sVar7 < 1)) {
      return;
    }
    if ((int)(uint)*(byte *)(*(int *)(local_14 + 0x10) + 5) <
        (int)((uint)*(byte *)(*(int *)(local_14 + 0x10) + 6) + (int)sVar7)) {
      *(undefined1 *)(*(int *)(local_14 + 0x10) + 6) =
           *(undefined1 *)(*(int *)(local_14 + 0x10) + 5);
      sVar7 = (ushort)*(byte *)(*(int *)(local_14 + 0x10) + 5) -
              (ushort)*(byte *)(*(int *)(local_14 + 0x10) + 6);
    }
    pcVar1 = (char *)(*(int *)(local_14 + 0x10) + 6);
    *pcVar1 = *pcVar1 + (char)sVar7;
    *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + (int)sVar7;
    if (*(int *)(param_1 + 0x150) < iVar4) {
      *(int *)(param_1 + 0x150) = iVar4;
    }
    FUN_0082ef00(local_c);
    if (local_18 == *(int *)(param_1 + 0x138)) {
      uVar6 = FUN_00412cd0();
      FUN_0082f200(param_1 + 0x134,uVar6);
    }
    else {
      *(char *)(local_18 + 0x10) = *(char *)(local_18 + 0x10) + (char)sVar7;
    }
    iVar5 = *(int *)(param_1 + 0x110);
    uVar2 = *(undefined1 *)(param_1 + 0x144);
    uVar3 = *(undefined1 *)(param_1 + 0x145);
    *(undefined4 *)(iVar5 + 0x108) = *(undefined4 *)(local_14 + 0x10);
    *(undefined1 *)(iVar5 + 0x104) = uVar3;
    *(undefined1 *)(iVar5 + 0x105) = uVar2;
    FUN_004704c0(iVar5);
  }
  FUN_004107f0(param_1);
  return;
}


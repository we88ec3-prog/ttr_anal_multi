
void FUN_00690b30(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00935bec;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar2 = *(int *)(*(int *)(in_ECX + 0x134) + 0x24c);
  uVar5 = 0;
  if ((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + 0xcc), iVar2 == 0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iVar2 + 0xdc);
  }
  if (*(int *)(iVar2 + 0x248) == 2) {
    FUN_00691440(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    (**(code **)(**(int **)(in_ECX + 0x138) + 0x90))(1);
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      puStack_10 = (undefined1 *)0x0;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    iVar1 = DAT_00fab1bc;
    iVar3 = *(int *)(in_ECX + 0x214) - *(int *)(in_ECX + 0x210);
    iVar2 = iVar3 >> 0x1f;
    iVar3 = iVar3 / 0x24 + iVar2;
    if (iVar3 != iVar2) {
      piVar4 = (int *)(*(int *)(in_ECX + 0x210) + 0x20);
      do {
        if (*piVar4 == DAT_00fab1bc) {
          FUN_0075cd30(*(undefined4 *)(in_ECX + 0x138));
          *(int *)(in_ECX + 0x20c) = iVar1;
          goto LAB_00690d24;
        }
        uVar5 = uVar5 + 1;
        piVar4 = piVar4 + 9;
      } while (uVar5 < (uint)(iVar3 - iVar2));
    }
    uVar6 = *(undefined4 *)(in_ECX + 0x138);
  }
  else {
    if (*(int *)(iVar2 + 0x248) != 3) {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x138) + 0x24c);
      if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0xcc), iVar2 != 0)) {
        FUN_006438f0(iVar2);
      }
      FUN_00757710();
      (**(code **)(**(int **)(in_ECX + 0x138) + 0x90))(0);
      goto LAB_00690d1a;
    }
    FUN_006915e0();
    (**(code **)(**(int **)(in_ECX + 0x138) + 0x90))(1);
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      puStack_10 = (undefined1 *)0x1;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    iVar2 = *(int *)(DAT_00fab130 + 0x5eac);
    iVar3 = *(int *)(in_ECX + 0x224) - *(int *)(in_ECX + 0x220);
    iVar1 = iVar3 >> 0x1f;
    iVar3 = iVar3 / 0x24 + iVar1;
    if (iVar3 != iVar1) {
      piVar4 = (int *)(*(int *)(in_ECX + 0x220) + 0x20);
      do {
        if (*piVar4 == iVar2) {
          FUN_0075cd30(*(undefined4 *)(in_ECX + 0x138));
          *(int *)(in_ECX + 0x20c) = iVar2;
          goto LAB_00690d24;
        }
        uVar5 = uVar5 + 1;
        piVar4 = piVar4 + 9;
      } while (uVar5 < (uint)(iVar3 - iVar1));
    }
    uVar6 = *(undefined4 *)(in_ECX + 0x138);
  }
  FUN_0075cd30(uVar6);
LAB_00690d1a:
  *(undefined4 *)(in_ECX + 0x20c) = 0;
LAB_00690d24:
  iVar2 = *(int *)(*(int *)(in_ECX + 0x138) + 0x24c);
  if (iVar2 != 0) {
    FUN_00749920(iVar2);
  }
  (**(code **)(**(int **)(in_ECX + 0x138) + 200))();
  ExceptionList = pvStack_18;
  return;
}



void FUN_0080f5b0(int param_1,undefined4 *param_2,char *param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  char cVar5;
  char *pcVar6;
  uint uVar7;
  undefined4 uVar8;
  char *_Str1;
  undefined4 *puVar9;
  bool bVar10;
  
  puVar1 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  bVar10 = true;
  cVar5 = *(char *)((int)puVar1 + 0x29);
  puVar4 = *(undefined4 **)(param_1 + 4);
  while (cVar5 == '\0') {
    uVar2 = puVar1[7];
    pcVar6 = (char *)(puVar1 + 3);
    if (0xf < (uint)puVar1[8]) {
      pcVar6 = *(char **)pcVar6;
    }
    uVar3 = *(uint *)(param_3 + 0x10);
    uVar7 = uVar3;
    if (uVar2 <= uVar3) {
      uVar7 = uVar2;
    }
    _Str1 = param_3;
    if (0xf < *(uint *)(param_3 + 0x14)) {
      _Str1 = *(char **)param_3;
    }
    uVar7 = __strnicmp(_Str1,pcVar6,uVar7);
    if (uVar7 == 0) {
      if (uVar3 < uVar2) {
        uVar7 = 0xffffffff;
      }
      else {
        uVar7 = (uint)(uVar3 != uVar2);
      }
    }
    bVar10 = (int)uVar7 < 0;
    if (bVar10) {
      puVar9 = (undefined4 *)*puVar1;
    }
    else {
      puVar9 = (undefined4 *)puVar1[2];
    }
    puVar4 = puVar1;
    puVar1 = puVar9;
    cVar5 = *(char *)((int)puVar9 + 0x29);
  }
  if (bVar10) {
    if (puVar4 == (undefined4 *)**(int **)(param_1 + 4)) {
      uVar8 = FUN_0080f6d0(param_3);
      bVar10 = true;
      goto LAB_0080f663;
    }
    FUN_00827b40();
  }
  pcVar6 = param_3;
  cVar5 = FUN_005436a0();
  if (cVar5 == '\0') {
    *param_2 = puVar4;
    *(undefined1 *)(param_2 + 1) = 0;
    return;
  }
  uVar8 = FUN_0080f6d0(pcVar6);
LAB_0080f663:
  FUN_004ad6b0(&param_3,bVar10,uVar8);
  *param_2 = param_3;
  *(undefined1 *)(param_2 + 1) = 1;
  return;
}


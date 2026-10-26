
/* WARNING: Removing unreachable block (ram,0x00574bbd) */

void FUN_00574b80(int param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  char cVar5;
  char *_Str2;
  uint uVar6;
  undefined4 *puVar7;
  char *_Str1;
  undefined4 *puVar8;
  bool bVar9;
  
  iVar4 = param_3;
  puVar7 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  bVar9 = true;
  cVar5 = *(char *)((int)puVar7 + 0x2d);
  puVar3 = *(undefined4 **)(param_1 + 4);
  while (cVar5 == '\0') {
    uVar1 = puVar7[7];
    _Str2 = (char *)(puVar7 + 3);
    if (0xf < (uint)puVar7[8]) {
      _Str2 = *(char **)_Str2;
    }
    uVar2 = *(uint *)(iVar4 + 0x1c);
    uVar6 = uVar2;
    if (uVar1 <= uVar2) {
      uVar6 = uVar1;
    }
    if (*(uint *)(iVar4 + 0x20) < 0x10) {
      _Str1 = (char *)(iVar4 + 0xc);
    }
    else {
      _Str1 = *(char **)(iVar4 + 0xc);
    }
    uVar6 = __strnicmp(_Str1,_Str2,uVar6);
    if (uVar6 == 0) {
      if (uVar2 < uVar1) {
        uVar6 = 0xffffffff;
      }
      else {
        uVar6 = (uint)(uVar2 != uVar1);
      }
    }
    bVar9 = (int)uVar6 < 0;
    if (bVar9) {
      puVar8 = (undefined4 *)*puVar7;
    }
    else {
      puVar8 = (undefined4 *)puVar7[2];
    }
    puVar3 = puVar7;
    puVar7 = puVar8;
    cVar5 = *(char *)((int)puVar8 + 0x2d);
  }
  if (bVar9) {
    if (puVar3 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar7 = (undefined4 *)FUN_00574ce0(&param_3,1,iVar4);
      *param_2 = *puVar7;
      *(undefined1 *)(param_2 + 1) = 1;
      return;
    }
    FUN_00574e80();
  }
  cVar5 = FUN_005436a0();
  if (cVar5 == '\0') {
    if (0xf < *(uint *)(iVar4 + 0x20)) {
      FUN_0089120c(*(undefined4 *)(iVar4 + 0xc));
    }
    *(undefined4 *)(iVar4 + 0x20) = 0xf;
    *(undefined4 *)(iVar4 + 0x1c) = 0;
    *(undefined1 *)(iVar4 + 0xc) = 0;
    FUN_0089120c(iVar4);
    *param_2 = puVar3;
    *(undefined1 *)(param_2 + 1) = 0;
    return;
  }
  puVar7 = (undefined4 *)FUN_00574ce0(&param_3,bVar9,iVar4);
  *param_2 = *puVar7;
  *(undefined1 *)(param_2 + 1) = 1;
  return;
}


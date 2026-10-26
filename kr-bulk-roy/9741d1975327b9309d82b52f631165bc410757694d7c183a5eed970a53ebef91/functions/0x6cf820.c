
/* WARNING: Removing unreachable block (ram,0x006cf85d) */

void FUN_006cf820(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  char cVar6;
  int *piVar7;
  uint uVar8;
  undefined4 *puVar9;
  char *_Str1;
  bool bVar10;
  
  iVar5 = param_2;
  bVar10 = true;
  cVar6 = *(char *)(DAT_00fc172c[1] + 0x2d);
  piVar7 = (int *)DAT_00fc172c[1];
  piVar4 = DAT_00fc172c;
  while (piVar3 = piVar7, cVar6 == '\0') {
    uVar1 = piVar3[7];
    piVar7 = piVar3 + 3;
    if (0xf < (uint)piVar3[8]) {
      piVar7 = (int *)*piVar7;
    }
    uVar2 = *(uint *)(iVar5 + 0x1c);
    uVar8 = uVar1;
    if (uVar2 < uVar1) {
      uVar8 = uVar2;
    }
    if (*(uint *)(iVar5 + 0x20) < 0x10) {
      _Str1 = (char *)(iVar5 + 0xc);
    }
    else {
      _Str1 = *(char **)(iVar5 + 0xc);
    }
    uVar8 = __strnicmp(_Str1,(char *)piVar7,uVar8);
    if (uVar8 == 0) {
      if (uVar2 < uVar1) {
        uVar8 = 0xffffffff;
      }
      else {
        uVar8 = (uint)(uVar2 != uVar1);
      }
    }
    bVar10 = (int)uVar8 < 0;
    if (bVar10) {
      piVar7 = (int *)*piVar3;
    }
    else {
      piVar7 = (int *)piVar3[2];
    }
    cVar6 = *(char *)((int)piVar7 + 0x2d);
    piVar4 = piVar3;
  }
  if (bVar10) {
    if (piVar4 == (int *)*DAT_00fc172c) {
      puVar9 = (undefined4 *)FUN_006cf970(&param_2,1);
      *param_1 = *puVar9;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_00574e80();
  }
  cVar6 = FUN_005436a0();
  if (cVar6 == '\0') {
    if (0xf < *(uint *)(iVar5 + 0x20)) {
      FUN_0089120c(*(undefined4 *)(iVar5 + 0xc));
    }
    *(undefined4 *)(iVar5 + 0x20) = 0xf;
    *(undefined4 *)(iVar5 + 0x1c) = 0;
    *(undefined1 *)(iVar5 + 0xc) = 0;
    FUN_0089120c(iVar5);
    *param_1 = piVar4;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
  puVar9 = (undefined4 *)FUN_006cf970(&param_2,bVar10);
  *param_1 = *puVar9;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


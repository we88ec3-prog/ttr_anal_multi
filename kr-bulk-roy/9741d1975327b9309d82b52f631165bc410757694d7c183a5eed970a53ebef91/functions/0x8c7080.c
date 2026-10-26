
int FUN_008c7080(int param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 0x10);
  uVar6 = (uint)(*(ushort *)(param_1 + 8) >> 1);
  iVar3 = FUN_008bc7d0(param_2,1,0,uVar6 + 1,0,&param_1);
  if (param_1 != 0) {
    return 0;
  }
  uVar5 = 0;
  if (uVar6 != 0) {
    iVar7 = iVar7 + -1;
    do {
      puVar1 = (undefined1 *)(iVar7 + 1);
      puVar2 = (undefined1 *)(iVar7 + 2);
      iVar7 = iVar7 + 2;
      uVar4 = CONCAT11(*puVar1,*puVar2);
      if (uVar4 == 0) break;
      if ((uVar4 < 0x20) || (0x7f < uVar4)) {
        uVar4 = 0x3f;
      }
      *(char *)(uVar5 + iVar3) = (char)uVar4;
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar6);
  }
  *(undefined1 *)(uVar5 + iVar3) = 0;
  return iVar3;
}


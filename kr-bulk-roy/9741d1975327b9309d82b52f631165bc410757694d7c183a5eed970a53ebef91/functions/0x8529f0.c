
undefined4 * FUN_008529f0(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090bca8;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar7 = *(undefined4 **)(param_1 + 4);
  cVar4 = '\x01';
  if (*(char *)((int)puVar7[1] + 0x1d) == '\0') {
    puVar1 = *(undefined4 **)(param_3 + 0x10);
    uVar2 = *puVar1;
    puVar8 = (undefined4 *)puVar7[1];
    do {
      puVar7 = puVar8;
      cVar4 = FUN_00854370(uVar2,puVar1,*(undefined4 *)puVar7[4],(undefined4 *)puVar7[4],uVar6);
      if (cVar4 == '\0') {
        puVar8 = (undefined4 *)puVar7[2];
      }
      else {
        puVar8 = (undefined4 *)*puVar7;
      }
    } while (*(char *)((int)puVar8 + 0x1d) == '\0');
  }
  if (cVar4 != '\0') {
    if (puVar7 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar7 = (undefined4 *)FUN_00852fa0(&param_3,1,puVar7,param_3);
      *param_2 = *puVar7;
      *(undefined1 *)(param_2 + 1) = 1;
      ExceptionList = local_10;
      return param_2;
    }
    FUN_00852060();
  }
  cVar5 = FUN_00854370(*(undefined4 *)puVar7[4],(undefined4 *)puVar7[4],
                       **(undefined4 **)(param_3 + 0x10),*(undefined4 **)(param_3 + 0x10),uVar6);
  iVar3 = param_3;
  if (cVar5 == '\0') {
    local_8 = 0;
    FUN_004ca160(**(undefined4 **)(param_3 + 0x10),*(undefined4 **)(param_3 + 0x10));
    FUN_0089120c(*(undefined4 *)(iVar3 + 0x10));
    FUN_0089120c(param_3);
    *(undefined1 *)(param_2 + 1) = 0;
  }
  else {
    puVar7 = (undefined4 *)FUN_00852fa0(&param_3,cVar4,puVar7,param_3);
    puVar7 = (undefined4 *)*puVar7;
    *(undefined1 *)(param_2 + 1) = 1;
  }
  *param_2 = puVar7;
  ExceptionList = local_10;
  return param_2;
}


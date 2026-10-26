
undefined4 * FUN_007ed8d0(undefined4 *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  char *in_ECX;
  uint uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914663;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  pcVar2 = in_ECX;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_ECX,(int)pcVar2 - (int)(in_ECX + 1));
  local_8 = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0xf;
  *(undefined1 *)(param_1 + 7) = 0;
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_2,(int)pcVar2 - (int)(param_2 + 1));
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_1[4] != 0) {
    uVar5 = 0;
    if (param_1[4] != 0) {
      do {
        puVar3 = param_1;
        if (0xf < (uint)param_1[5]) {
          puVar3 = (undefined4 *)*param_1;
        }
        if (*(char *)((int)puVar3 + uVar5) == '\\') {
          puVar3 = param_1;
          if (0xf < (uint)param_1[5]) {
            puVar3 = (undefined4 *)*param_1;
          }
          *(undefined1 *)((int)puVar3 + uVar5) = 0x2f;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)param_1[4]);
    }
    uVar5 = param_1[5];
    puVar3 = param_1;
    if (0xf < uVar5) {
      puVar3 = (undefined4 *)*param_1;
    }
    if (*(char *)((int)puVar3 + param_1[4] + -1) != '/') {
      puVar3 = param_1;
      if (0xf < uVar5) {
        puVar3 = (undefined4 *)*param_1;
      }
      iVar4 = param_1[4] + (int)puVar3;
      puVar3 = param_1;
      if (0xf < uVar5) {
        puVar3 = (undefined4 *)*param_1;
      }
      if (iVar4 != 0) {
        iVar4 = iVar4 - (int)puVar3;
      }
      FUN_004329c0(iVar4,1,0x2f);
    }
  }
  ExceptionList = local_10;
  return param_1;
}


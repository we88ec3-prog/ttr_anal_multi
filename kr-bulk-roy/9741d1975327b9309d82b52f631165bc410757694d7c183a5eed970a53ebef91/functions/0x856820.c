
undefined4 * FUN_00856820(undefined4 *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00913f69;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar3 = (undefined4 *)FUN_007b2620();
  *puVar3 = *(undefined4 *)(in_ECX + 4);
  puVar3[1] = *(undefined4 *)(in_ECX + 4);
  puVar3[2] = *(undefined4 *)(in_ECX + 4);
  *(undefined2 *)(puVar3 + 0xe) = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (puVar3 + 3 != (undefined4 *)0x0) {
    pcVar2 = (char *)*param_1;
    puVar3[8] = 0xf;
    puVar3[7] = 0;
    *(undefined1 *)(puVar3 + 3) = 0;
    pcVar4 = pcVar2;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar2,(int)pcVar4 - (int)(pcVar2 + 1));
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00867d70(puVar3 + 10,param_1 + 1);
  }
  ExceptionList = local_10;
  return puVar3;
}


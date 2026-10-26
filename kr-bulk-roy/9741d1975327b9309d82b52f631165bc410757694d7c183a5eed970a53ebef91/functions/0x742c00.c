
undefined4 * FUN_00742c00(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911de9;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  puVar1 = (undefined4 *)FUN_007b2620();
  *puVar1 = *(undefined4 *)(in_ECX + 4);
  puVar1[1] = *(undefined4 *)(in_ECX + 4);
  puVar1[2] = *(undefined4 *)(in_ECX + 4);
  *(undefined2 *)(puVar1 + 0xe) = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (puVar1 + 3 != (undefined4 *)0x0) {
    puVar1[7] = 0;
    puVar1[8] = 7;
    *(undefined2 *)(puVar1 + 3) = 0;
    FUN_00741800(param_1,0);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00742260(puVar1 + 10);
  }
  *unaff_FS_OFFSET = local_10;
  return puVar1;
}


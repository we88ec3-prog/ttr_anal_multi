
undefined4 * FUN_0073c450(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091f355;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  param_1[1] = 0;
  param_1[2] = 0;
  local_8 = 0;
  *param_1 = CFontDriver_FreeType::vftable;
  FUN_0073d000(param_1 + 3);
  puVar1 = param_1 + 5;
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00740780(puVar1,1);
  FUN_00740780(puVar1,1);
  FUN_00740780(puVar1,1);
  FUN_00740780(puVar1,1);
  FUN_00740780(puVar1,1);
  FUN_00740780(puVar1,1);
  FUN_00740780(puVar1,1);
  FUN_00740780(puVar1,1);
  FUN_00740780(puVar1,0);
  FUN_00740780(puVar1,0);
  FUN_00740780(puVar1,0);
  FUN_00740780(puVar1,0);
  FUN_00740780(puVar1,0);
  FUN_00740780(puVar1,0);
  FUN_00740780(puVar1,0);
  FUN_00740780(puVar1,0);
  FUN_00740780(puVar1,0);
  FUN_00740780(puVar1,0);
  FUN_00740780(puVar1,0);
  FUN_0073d170();
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


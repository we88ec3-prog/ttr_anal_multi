
void FUN_00746c60(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *in_ECX;
  int *piVar5;
  undefined4 uVar6;
  undefined1 auStack_164 [4];
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 *puStack_150;
  int *piStack_14c;
  undefined1 local_148 [160];
  int *local_a8;
  undefined1 local_a0 [120];
  int *local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0090a776;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_164;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffe90;
  ExceptionList = &local_14;
  _eh_vector_constructor_iterator_
            (local_148,0x14,8,(_func_void_void_ptr *)&LAB_0074d950,FUN_005f5d10);
  local_a8 = (int *)0x0;
  local_c = 0;
  _eh_vector_constructor_iterator_
            (local_a0,0x14,6,(_func_void_void_ptr *)&LAB_0074d950,FUN_005f5d10);
  local_28 = (int *)0x0;
  local_c._0_1_ = 1;
  local_15c = in_ECX[3];
  local_160 = in_ECX[2];
  local_158 = in_ECX[4];
  local_154 = in_ECX[5];
  if ((((uint)in_ECX[10] >> 8 & 1) == 0) ||
     ((in_ECX[0x18] != 0 && (cVar1 = FUN_00746420(uVar2), cVar1 == '\0')))) goto LAB_00746e23;
  iVar3 = (**(code **)*in_ECX)();
  if ((iVar3 == 2) || (iVar3 == 6)) {
    uVar6 = 0xff00ff00;
    if ((*(byte *)(in_ECX + 10) & 0x30) == 0) {
      uVar6 = 0xff780078;
    }
LAB_00746dad:
    FUN_0076fa20(local_148,param_1,param_2,uVar6,local_160,local_15c,local_158,local_154,param_3,
                 param_4);
    FUN_0076fc70();
  }
  else if (iVar3 == 0xc) {
    uVar6 = 0xffccff33;
    goto LAB_00746dad;
  }
  piStack_14c = (int *)in_ECX[0x19];
  piVar5 = (int *)*piStack_14c;
  if (piVar5 != piStack_14c) {
    puStack_150 = in_ECX + 3;
    do {
      iVar3 = *(int *)piVar5[2];
      iVar4 = FUN_008fed10(param_3,param_4);
      iVar4 = FUN_008fed10(iVar4 + param_2);
      (**(code **)(iVar3 + 0xb8))(iVar4 + param_1);
      piVar5 = (int *)*piVar5;
    } while (piVar5 != piStack_14c);
  }
LAB_00746e23:
  local_c._0_1_ = 2;
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
    local_28 = (int *)0x0;
  }
  local_c = (uint)local_c._1_3_ << 8;
  _eh_vector_destructor_iterator_(local_a0,0x14,6,FUN_005f5d10);
  local_c = 3;
  if (local_a8 != (int *)0x0) {
    (**(code **)(*local_a8 + 8))(local_a8);
    local_a8 = (int *)0x0;
  }
  local_c = 0xffffffff;
  _eh_vector_destructor_iterator_(local_148,0x14,8,FUN_005f5d10);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_164);
  return;
}



int FUN_008e5980(int *param_1,undefined4 param_2)

{
  int in_EAX;
  int iVar1;
  int *in_ECX;
  int local_10;
  int local_c;
  short local_8 [2];
  
  (*(code *)**(undefined4 **)(in_EAX + 4))(param_1,0,0,param_2);
  param_1[0x14] = 0;
  param_1[0x13] = 0;
  param_1[0x16] = 0;
  param_1[0x15] = 0;
  *(undefined2 *)(param_1 + 0x17) = 0;
  param_1[0x12] = (int)in_ECX;
  *(undefined1 *)((int)param_1 + 0x5e) = 0;
  local_c = FUN_008e58b0();
  if ((((local_c == 0) || (((char)local_c == '\x02' && (local_c = FUN_008e58b0(), local_c == 0))))
      && (local_c = FUN_008b97e0(), local_c == 0)) &&
     (local_c = FUN_008e5850(local_8), local_c == 0)) {
    if (local_8[0] == -0x7fff) {
      *(undefined1 *)(param_1 + 0x17) = 1;
    }
    else {
      local_c = FUN_008b97e0();
      if (local_c != 0) goto LAB_008e5ad1;
      local_10 = in_ECX[1];
    }
    if (in_ECX[5] == 0) {
      param_1[0x13] = in_ECX[2] + *in_ECX;
      param_1[0x14] = local_10;
      *(undefined1 *)((int)param_1 + 0x5d) = 1;
      local_c = FUN_008b9820();
      if (local_c == 0) {
LAB_008e5ab7:
        iVar1 = param_1[0x13];
        param_1[2] = param_1[0x14] + iVar1;
        param_1[1] = iVar1;
        *param_1 = iVar1;
        return 0;
      }
    }
    else {
      iVar1 = FUN_008baee0(param_2,local_10,&local_c);
      param_1[0x13] = iVar1;
      if ((local_c == 0) && (local_c = FUN_008bab70(), local_c == 0)) {
        param_1[0x14] = local_10;
        goto LAB_008e5ab7;
      }
    }
  }
LAB_008e5ad1:
  if (*(char *)((int)param_1 + 0x5d) == '\0') {
    FUN_008b9f80(param_2,param_1[0x13]);
    param_1[0x13] = 0;
  }
  return local_c;
}


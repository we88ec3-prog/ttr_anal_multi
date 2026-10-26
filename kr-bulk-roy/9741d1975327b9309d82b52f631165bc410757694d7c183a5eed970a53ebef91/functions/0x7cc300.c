
undefined4 FUN_007cc300(undefined4 param_1,undefined4 *param_2)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  *param_2 = 0;
  local_8 = 0;
  iVar1 = FUN_00716eb0();
  if (-1 < iVar1) {
    in_ECX = local_8;
    in_EAX = local_c;
  }
  if ((*(short *)(in_ECX + 4) == 0) || (*(short *)(in_ECX + 4) == 2)) {
    FUN_00733ea0();
  }
  if ((*(short *)(in_ECX + 4) == 1) || (*(short *)(in_ECX + 4) == 2)) {
    FUN_00733ea0();
  }
  uVar2 = FUN_007cc120(param_1,in_EAX + -8);
  if (-1 < iVar1) {
    FUN_00891d3d(0);
  }
  return uVar2;
}


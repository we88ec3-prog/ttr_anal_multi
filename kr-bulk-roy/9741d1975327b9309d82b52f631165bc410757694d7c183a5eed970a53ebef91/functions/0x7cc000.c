
undefined1 FUN_007cc000(undefined4 param_1)

{
  undefined1 uVar1;
  int in_EAX;
  int iVar2;
  int in_ECX;
  int local_c;
  int local_8;
  
  local_8 = 0;
  iVar2 = FUN_00716eb0();
  if (-1 < iVar2) {
    in_ECX = local_8;
    in_EAX = local_c;
  }
  if ((*(short *)(in_ECX + 4) == 0) || (*(short *)(in_ECX + 4) == 2)) {
    FUN_00733ea0();
  }
  if ((*(short *)(in_ECX + 4) == 1) || (*(short *)(in_ECX + 4) == 2)) {
    FUN_00733ea0();
  }
  uVar1 = FUN_00862450(param_1,in_EAX + -8);
  if (-1 < iVar2) {
    FUN_00891d3d(0);
  }
  return uVar1;
}


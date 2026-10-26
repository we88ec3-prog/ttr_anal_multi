
undefined4 FUN_00447870(int param_1)

{
  int *in_ECX;
  
  switch(param_1 + -1) {
  case 0:
  case 2:
    FUN_0044a300(0xffffffff);
    return 1;
  case 1:
  case 3:
    FUN_0044a300(1);
    return 1;
  }
  if (param_1 != 0x2af9) {
    return 0;
  }
  (**(code **)(*in_ECX + 0xd4))();
  return 1;
}


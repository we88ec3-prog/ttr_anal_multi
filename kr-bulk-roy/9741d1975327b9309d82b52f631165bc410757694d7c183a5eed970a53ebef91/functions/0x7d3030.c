
void FUN_007d3030(undefined4 *param_1)

{
  int unaff_EDI;
  undefined4 local_3c [4];
  undefined4 local_2c;
  undefined4 local_1c;
  
  _memset(local_3c,0,0x34);
  local_1c = 0x3f800000;
  local_2c = 0x3f800000;
  local_3c[0] = 0x3f800000;
  FUN_00790dc0(*param_1);
  FUN_00790e90(param_1[1]);
  FUN_00790f60(param_1[2]);
  FUN_00780890();
  *(undefined4 *)(unaff_EDI + 0x34) = 0;
  *(undefined4 *)(unaff_EDI + 0x38) = 0;
  *(undefined4 *)(unaff_EDI + 0x3c) = 0;
  *(undefined4 *)(unaff_EDI + 0x40) = 0x3f800000;
  FUN_0077efc0();
  return;
}


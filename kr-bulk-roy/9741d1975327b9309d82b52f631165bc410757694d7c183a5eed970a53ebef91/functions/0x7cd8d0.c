
void FUN_007cd8d0(int param_1)

{
  undefined4 *unaff_EDI;
  undefined4 local_3c [4];
  undefined4 local_2c;
  undefined4 local_1c;
  
  *(undefined4 *)(param_1 + 0x48) = *unaff_EDI;
  *(undefined4 *)(param_1 + 0x4c) = unaff_EDI[1];
  *(undefined4 *)(param_1 + 0x50) = unaff_EDI[2];
  _memset(local_3c,0,0x34);
  local_1c = 0x3f800000;
  local_2c = 0x3f800000;
  local_3c[0] = 0x3f800000;
  FUN_00790dc0(*unaff_EDI);
  FUN_00790e90(unaff_EDI[1]);
  FUN_00790f60(unaff_EDI[2]);
  FUN_00780890();
  FUN_0077efc0();
  return;
}


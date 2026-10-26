
void FUN_0079a6b0(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *unaff_EDI;
  int *local_100;
  undefined1 local_fc [64];
  undefined1 local_bc [64];
  undefined1 local_7c [68];
  undefined1 local_38 [24];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0xec) != 0) {
    (**(code **)(**(int **)(iVar1 + 0xec) + 4))(*(int **)(iVar1 + 0xec));
    local_100 = *(int **)(iVar1 + 0xec);
  }
  (**(code **)(*local_100 + 0xc0))(local_100,local_38);
  (**(code **)(*local_100 + 0xb4))(local_100,2,local_bc);
  (**(code **)(*local_100 + 0xb4))(local_100,3,local_fc);
  D3DXMatrixAffineTransformation(local_7c,0x3f800000,0,0,param_2);
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  D3DXVec3Project(&local_20,&local_14,local_38,local_fc,local_bc,local_7c);
  (**(code **)(*local_100 + 8))(local_100);
  *unaff_EDI = local_20;
  unaff_EDI[1] = local_1c;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


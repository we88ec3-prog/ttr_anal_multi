
void FUN_008657c0(float param_1,float param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int *in_ECX;
  undefined4 extraout_EDX;
  int *unaff_EDI;
  int local_2c;
  int local_18;
  int local_14;
  
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar1 = (int *)*in_ECX;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *in_ECX = 0;
  }
  iVar4 = (**(code **)(*unaff_EDI + 0xc0))();
  if (-1 < iVar4) {
    in_ECX[10] = (int)param_1;
    in_ECX[9] = 1;
    in_ECX[0xb] = (int)param_2;
    fVar2 = (float)local_18;
    if (local_18 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    local_2c = (int)(longlong)ROUND(fVar2 * param_1);
    in_ECX[3] = local_2c;
    fVar2 = (float)local_14;
    if (local_14 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    local_2c = (int)(longlong)ROUND(fVar2 * param_2);
    in_ECX[5] = param_3;
    in_ECX[7] = param_5;
    in_ECX[4] = local_2c;
    in_ECX[6] = param_4;
    in_ECX[1] = 0;
    in_ECX[2] = 2;
    in_ECX[8] = param_6;
    (**(code **)(*unaff_EDI + 0x74))();
    __security_check_cookie
              (uVar3 ^ (uint)&stack0xfffffffc,extraout_EDX,local_2c,param_3,param_4,param_5,param_6)
    ;
    return;
  }
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}


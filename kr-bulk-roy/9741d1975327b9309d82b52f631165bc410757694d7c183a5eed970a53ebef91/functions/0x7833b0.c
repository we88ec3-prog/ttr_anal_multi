
void FUN_007833b0(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  int unaff_EDI;
  bool bVar4;
  undefined4 local_10;
  undefined4 local_c;
  
  if (((**(int **)(in_ECX + 0x20) == in_ECX + 0x48) && (param_4 == 1)) &&
     (*(int *)(in_ECX + 0x44) == 0)) {
    bVar4 = param_2 != 0;
    param_2 = param_2 + -1;
    param_3 = param_3 + -1 + (uint)bVar4;
  }
  if ((((*(int *)(in_ECX + 0x54) != 0) && (cVar2 = FUN_00783ac0(), cVar2 != '\0')) &&
      (((param_2 == 0 && param_3 == 0 && (param_4 == 1)) ||
       (iVar3 = __fseeki64(*(FILE **)(in_ECX + 0x54),CONCAT44(param_4,param_3),unaff_EDI),
       iVar3 == 0)))) &&
     (iVar3 = _fgetpos(*(FILE **)(in_ECX + 0x54),(fpos_t *)&local_10), iVar3 == 0)) {
    FUN_00783c00();
    param_1[2] = local_10;
    uVar1 = *(undefined4 *)(in_ECX + 0x4c);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = local_c;
    param_1[4] = uVar1;
    return;
  }
  param_1[1] = 0xffffffff;
  *param_1 = 0xffffffff;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}


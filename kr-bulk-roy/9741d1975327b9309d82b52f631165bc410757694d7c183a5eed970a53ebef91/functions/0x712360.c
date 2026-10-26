
void FUN_00712360(uint param_1)

{
  uint *puVar1;
  int *in_EAX;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  undefined4 uVar4;
  
  FUN_007122a0();
  switch(*in_EAX) {
  case 1:
    FUN_00711c00(1);
    in_EAX[2] = param_1;
    *in_EAX = 0xc;
    return;
  case 2:
  case 3:
    uVar4 = *(undefined4 *)(in_ECX[3] + 8);
    uVar3 = ((uint)(*in_EAX == 2) << 0x11 | param_1) << 6 | 2;
    break;
  case 4:
    uVar4 = *(undefined4 *)(in_ECX[3] + 8);
    uVar3 = (in_EAX[2] << 8 | param_1) << 6 | 1;
    break;
  case 5:
    iVar2 = FUN_00712090();
    FUN_00713370((iVar2 << 8 | param_1) << 6 | 1,*(undefined4 *)(in_ECX[3] + 8));
    in_EAX[2] = param_1;
    *in_EAX = 0xc;
    return;
  default:
    goto switchD_00712385_caseD_6;
  case 0xb:
    puVar1 = (uint *)(*(int *)(*in_ECX + 0xc) + in_EAX[2] * 4);
    *puVar1 = *puVar1 ^ (param_1 << 6 ^ *(uint *)(*(int *)(*in_ECX + 0xc) + in_EAX[2] * 4)) & 0x3fc0
    ;
    in_EAX[2] = param_1;
    *in_EAX = 0xc;
    return;
  case 0xc:
    if (param_1 != in_EAX[2]) {
      uVar4 = *(undefined4 *)(in_ECX[3] + 8);
      uVar3 = (in_EAX[2] << 0x11 | param_1) << 6;
      break;
    }
    goto LAB_00712473;
  }
  FUN_00713370(uVar3,uVar4);
LAB_00712473:
  in_EAX[2] = param_1;
  *in_EAX = 0xc;
switchD_00712385_caseD_6:
  return;
}


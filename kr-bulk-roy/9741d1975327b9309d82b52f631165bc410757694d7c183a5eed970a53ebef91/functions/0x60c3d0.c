
void FUN_0060c3d0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 0x10) != 0x578) {
    return;
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x280) + 0x28) & 0x100) != 0) {
    return;
  }
  switch(*(undefined2 *)(in_ECX + 0x27c)) {
  case 0:
    FUN_00444960();
    break;
  case 2:
    goto switchD_0060c414_caseD_2;
  case 3:
    FUN_00444960();
    FUN_0041e560();
  case 1:
    FUN_00444960();
    break;
  case 4:
    FUN_00444960();
    goto LAB_0060c475;
  case 5:
    FUN_00444960();
LAB_0060c475:
    FUN_0041e560();
switchD_0060c414_caseD_2:
    FUN_00444960();
    break;
  default:
    goto switchD_0060c414_default;
  }
  FUN_0041e560();
switchD_0060c414_default:
  return;
}


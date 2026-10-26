
void FUN_0072fd20(FILE *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int in_ECX;
  
  if (param_1 != (FILE *)0x0) {
    _fprintf(param_1,"<?xml ");
  }
  if (param_3 != 0) {
    FUN_00401fc0("<?xml ",6);
  }
  if (*(int *)(in_ECX + 0x54) != 0) {
    if (param_1 != (FILE *)0x0) {
      piVar1 = (int *)(in_ECX + 0x44);
      if (0xf < *(uint *)(in_ECX + 0x58)) {
        piVar1 = (int *)*piVar1;
      }
      _fprintf(param_1,"version=\"%s\" ",piVar1);
    }
    if (param_3 != 0) {
      FUN_00401fc0("version=\"",9);
      FUN_00401ed0(in_ECX + 0x44,0,0xffffffff);
      FUN_00401fc0(&DAT_00c44cbc,2);
    }
  }
  if (*(int *)(in_ECX + 0x70) != 0) {
    if (param_1 != (FILE *)0x0) {
      piVar1 = (int *)(in_ECX + 0x60);
      if (0xf < *(uint *)(in_ECX + 0x74)) {
        piVar1 = (int *)*piVar1;
      }
      _fprintf(param_1,"encoding=\"%s\" ",piVar1);
    }
    if (param_3 != 0) {
      FUN_00401fc0("encoding=\"",10);
      FUN_00401ed0(in_ECX + 0x60,0,0xffffffff);
      FUN_00401fc0(&DAT_00c44cbc,2);
    }
  }
  if (*(int *)(in_ECX + 0x8c) != 0) {
    if (param_1 != (FILE *)0x0) {
      piVar1 = (int *)(in_ECX + 0x7c);
      if (0xf < *(uint *)(in_ECX + 0x90)) {
        piVar1 = (int *)*piVar1;
      }
      _fprintf(param_1,"standalone=\"%s\" ",piVar1);
    }
    if (param_3 != 0) {
      FUN_00401fc0("standalone=\"",0xc);
      FUN_00401ed0(in_ECX + 0x7c,0,0xffffffff);
      FUN_00401fc0(&DAT_00c44cbc,2);
    }
  }
  if (param_1 != (FILE *)0x0) {
    _fprintf(param_1,"?>");
  }
  if (param_3 != 0) {
    FUN_00401fc0(&DAT_00c44d00,2);
  }
  return;
}



void FUN_006d1b50(int param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int local_c;
  FILE *local_8;
  
  local_8 = (FILE *)0x0;
  _fopen_s(&local_8,"Virualkey.dll","w+b");
  if (local_8 != (FILE *)0x0) {
    local_c = 0;
    piVar1 = (int *)(param_1 + 0x504);
    do {
      uVar2 = 0;
      uVar3 = piVar1[1] - *piVar1 >> 2;
      if (uVar3 != 0) {
        do {
          _fprintf(local_8,"%d %d\n",local_c,*(undefined4 *)(*piVar1 + uVar2 * 4));
          uVar2 = uVar2 + 1;
        } while (uVar2 < uVar3);
      }
      local_c = local_c + 1;
      piVar1 = piVar1 + 4;
    } while (local_c < 0x28);
    _fclose(local_8);
  }
  return;
}


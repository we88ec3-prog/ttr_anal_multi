
void FUN_0083d190(void)

{
  int *piVar1;
  float fVar2;
  int in_ECX;
  undefined4 *puStack_264;
  int *piStack_260;
  undefined4 uStack_25c;
  int iStack_258;
  int *piStack_254;
  undefined1 *puStack_250;
  undefined1 *puStack_24c;
  undefined1 auStack_240 [32];
  int iStack_220;
  int iStack_21c;
  undefined1 local_218 [524];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_240;
  if (*(int *)(in_ECX + 0xec) != 0) {
    puStack_24c = local_218;
    puStack_250 = (undefined1 *)0x142;
    piStack_254 = (int *)0x83d1cb;
    D3DXDeclaratorFromFVF();
    piStack_254 = *(int **)(in_ECX + 0xec);
    puStack_24c = (undefined1 *)(in_ECX + 0x448);
    puStack_250 = local_218;
    iStack_258 = 0x83d1e8;
    (**(code **)(*piStack_254 + 0x158))();
    iStack_258 = *(undefined4 *)(in_ECX + 0x450);
    piStack_260 = (int *)0x83d1f5;
    FUN_0083dfa0();
    iStack_258 = in_ECX + 0x350;
    uStack_25c = 0x83d201;
    FUN_00838ff0();
    iStack_258 = in_ECX + 0x178;
    uStack_25c = 0x83d20d;
    FUN_008641f0();
    iStack_258 = in_ECX + 0x134;
    uStack_25c = 0x83d219;
    FUN_00863d20();
    iStack_258 = in_ECX + 0xf0;
    uStack_25c = 0x83d225;
    FUN_00863650();
    piStack_260 = *(int **)(in_ECX + 0xec);
    iStack_258 = 2;
    uStack_25c = 0x16;
    puStack_264 = (undefined4 *)0x83d23a;
    (**(code **)(*piStack_260 + 0xe4))();
    puStack_264 = (undefined4 *)(in_ECX + 0x42c);
    (**(code **)(**(int **)(in_ECX + 0xec) + 0x98))(*(int **)(in_ECX + 0xec),0);
    (**(code **)(**(int **)(in_ECX + 0xec) + 0xa0))(*(int **)(in_ECX + 0xec),in_ECX + 0x430);
    piVar1 = *(int **)(in_ECX + 0x42c);
    (**(code **)(*piVar1 + 0x30))(piVar1,&puStack_264);
    fVar2 = (float)iStack_220;
    if (iStack_220 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    *(float *)(in_ECX + 0x434) = fVar2;
    fVar2 = (float)iStack_21c;
    if (iStack_21c < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    *(float *)(in_ECX + 0x438) = fVar2;
    puStack_24c = (undefined1 *)0x83d2b6;
    FUN_00867210();
    puStack_24c = (undefined1 *)0x83d2bb;
    FUN_0083e5b0();
  }
  __security_check_cookie(local_c ^ (uint)auStack_240);
  return;
}


<template>
  <div id="prof">
    <div style="height: 100vh;">
      

    <div :class="center" class="navbar navbar-light sticky-top border-bottom bg-dark" style="height: 15vh;">
      <img :src="require('./assets/image.png')" style="max-height:8vh; width: auto; border-radius: 80%;">
    </div>

    <div class="d-flex">
      <div class="fw-bold text-light fs-4 ms-5 px-3 py-1 " :class="[center, { 'bg-secondary': hoverHOME }]" @mouseover="hoverBooking = true" @mouseleave="hoverBooking = false"  style="border: 3px solid white; border-radius: 10px;">
        HOME
      </div>
      <div>
      </div>
    </div>


    </div>
  </div>
</template>

<script>
// @ is an alias to /src
export default {
  name: "ProfilePage",
  data() {
    return {
      previousRoutes: [],
      search: "",
      center: {
        "d-flex": true,
        "justify-content-center": true,
        "align-items-center": true,
      },
    };
  },
  mounted() {},
  methods: {},
  watch: {
    $route(to, from) {
      this.previousRoutes.push(from); // เมื่อมีการเปลี่ยนเส้นทางใหม่ ให้เก็บเส้นทางก่อนหน้าลงในอาร์เรย์
    },
  },
};
</script>

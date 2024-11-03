<template>
  <div id="app">
    <div class="bg-light my-3"></div>

    <div style="height: 90vh">
      <div class="d-flex">
        <div class="flex-fill"></div>


        
        <div class="flex-fill" style="height: 90vh; width: 90%">
          <div class="d-flex flex-column bg-danger" style="height: 20vh; width: 100%">
            <img
              :src="require('@/assets/image2.png')"
              class="my-0 mx-0"
              style="max-height: 15vh; max-width: 15vh; border-radius: 80%"
            />
          </div>






          <div class="d-flex">
            <div class="flex-fill bg-success" style="height: 70vh; width: 90%">
              <img
                :src="require('@/assets/image2.png')"
                class="my-0 mx-0"
                style="max-height: 10vh; max-width: 10vh; border-radius: 80%"
              />
            </div>



            <div class="flex-fill bg-warning" style="height: 70vh; width: 90%">
              <img
                :src="require('@/assets/image2.png')"
                class="my-0 mx-0"
                style="max-height: 10vh; max-width: 10vh; border-radius: 80%"
              />
            </div>



          </div>
        </div>
        <div class="flex-fill"></div>
      </div>
    </div>
  </div>
</template>

<script>
// @ is an alias to /src
export default {
  name: "HistoryPage",
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
